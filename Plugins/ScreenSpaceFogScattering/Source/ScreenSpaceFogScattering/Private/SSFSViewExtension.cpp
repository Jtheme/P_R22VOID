// Copyright 2023 Dmitry Karpukhin. All Rights Reserved.

#include "SSFSViewExtension.h"
#include "PostProcess/PostProcessing.h"
#include "PostProcess/PostProcessMaterial.h"
#include "RenderGraph.h"
#include "ScreenPass.h"
#include "Runtime/Launch/Resources/Version.h"

namespace
{
	// Console variables
	TAutoConsoleVariable<int32> CVarSSFS(
	TEXT("r.SSFS"),
	1,
	TEXT("Enable or disable the Screen Space Fog Scattering post process effect."),
	ECVF_RenderThreadSafe);

	TAutoConsoleVariable<int32> CVarSSFSPassAmount(
	TEXT("r.SSFS.PassAmount"),
	8,
	TEXT("Number of passes to render the fog scattering.\n")
	TEXT("Max number of passes is clamped to 12."),
	ECVF_RenderThreadSafe);

	TAutoConsoleVariable<float> CVarSSFSRadius(
	TEXT("r.SSFS.Radius"),
	0.85,
	TEXT("The progressive radius of the fog scattering."),
	ECVF_RenderThreadSafe);

	TAutoConsoleVariable<float> CVarSSFSIntensity(
	TEXT("r.SSFS.Intensity"),
	1.0,
	TEXT("Intensity of the effect scaled by the Exponential Height Fog."),
	ECVF_RenderThreadSafe);
	
	// Shader declarations

	// Struct to include common shader parameters
	BEGIN_SHADER_PARAMETER_STRUCT(FCommonParameters, )
		SHADER_PARAMETER_STRUCT_REF(FViewUniformShaderParameters, ViewUniformBuffer)

		SHADER_PARAMETER(FIntRect, ViewportRect)
		SHADER_PARAMETER(FVector2f, ViewportInvSize)
		SHADER_PARAMETER(FVector2f, UVScale)

		SHADER_PARAMETER_RDG_TEXTURE(Texture2D, InputTexture)
		SHADER_PARAMETER_SAMPLER(SamplerState, InputSampler)
	END_SHADER_PARAMETER_STRUCT()

	class FSetupCS : public FGlobalShader
	{
	public:
		DECLARE_GLOBAL_SHADER(FSetupCS);
		SHADER_USE_PARAMETER_STRUCT(FSetupCS, FGlobalShader);

		BEGIN_SHADER_PARAMETER_STRUCT(FParameters, )
			SHADER_PARAMETER_STRUCT_INCLUDE(FCommonParameters, CommonParameters)
			SHADER_PARAMETER(float, Intensity)
			SHADER_PARAMETER_RDG_TEXTURE(Texture2D, DepthTexture)
			SHADER_PARAMETER(FVector4f, ExponentialFogParameters)
			SHADER_PARAMETER(FVector4f, ExponentialFogParameters2)
			SHADER_PARAMETER(FVector4f, ExponentialFogParameters3)
			//SHADER_PARAMETER(FVector4f, ExponentialFogColorParameter)
			SHADER_PARAMETER(float, FogMaxOpacity)
			SHADER_PARAMETER(float, ApplyVolumetricFog)
			SHADER_PARAMETER(float, VolumetricFogStartDistance)
			SHADER_PARAMETER_RDG_TEXTURE(Texture3D, IntegratedLightScattering)
			SHADER_PARAMETER_RDG_TEXTURE_UAV(RWTexture2D<float4>, Output)
		END_SHADER_PARAMETER_STRUCT()

		static bool ShouldCompilePermutation(const FGlobalShaderPermutationParameters& Parameters)
		{
			return IsFeatureLevelSupported(Parameters.Platform, ERHIFeatureLevel::SM5);
		}
	};
	IMPLEMENT_GLOBAL_SHADER(FSetupCS, "/Plugins/ScreenSpaceFogScattering/SSFSSetup.usf", "SetupCS", SF_Compute);

	class FDownsampleCS : public FGlobalShader
	{
	public:
		DECLARE_GLOBAL_SHADER(FDownsampleCS);
		SHADER_USE_PARAMETER_STRUCT(FDownsampleCS, FGlobalShader);

		BEGIN_SHADER_PARAMETER_STRUCT(FParameters, )
			SHADER_PARAMETER_STRUCT_INCLUDE(FCommonParameters, CommonParameters)
			SHADER_PARAMETER(FVector2f, InputSize)
			SHADER_PARAMETER_RDG_TEXTURE(Texture2D, FogMaskTexture)
			SHADER_PARAMETER_RDG_TEXTURE_UAV(RWTexture2D<float4>, Output)
		END_SHADER_PARAMETER_STRUCT()

		static bool ShouldCompilePermutation(const FGlobalShaderPermutationParameters& Parameters)
		{
			return IsFeatureLevelSupported(Parameters.Platform, ERHIFeatureLevel::SM5);
		}
	};
	IMPLEMENT_GLOBAL_SHADER(FDownsampleCS, "/Plugins/ScreenSpaceFogScattering/SSFSDownsample.usf", "DownsampleCS", SF_Compute);

	class FUpsampleCombineCS : public FGlobalShader
	{
	public:
		DECLARE_GLOBAL_SHADER(FUpsampleCombineCS);
		SHADER_USE_PARAMETER_STRUCT(FUpsampleCombineCS, FGlobalShader);

		BEGIN_SHADER_PARAMETER_STRUCT(FParameters, )
			SHADER_PARAMETER_STRUCT_INCLUDE(FCommonParameters, CommonParameters)
			SHADER_PARAMETER(FVector2f, InputSize)
			SHADER_PARAMETER_RDG_TEXTURE(Texture2D, PreviousTexture)
			SHADER_PARAMETER(float, Radius)
			SHADER_PARAMETER_RDG_TEXTURE_UAV(RWTexture2D<float4>, Output)
		END_SHADER_PARAMETER_STRUCT()

		static bool ShouldCompilePermutation(const FGlobalShaderPermutationParameters& Parameters)
		{
			return IsFeatureLevelSupported(Parameters.Platform, ERHIFeatureLevel::SM5);
		}
	};
	IMPLEMENT_GLOBAL_SHADER(FUpsampleCombineCS, "/Plugins/ScreenSpaceFogScattering/SSFSUpsampleCombine.usf", "UpsampleCombineCS", SF_Compute);

	class FRecombineCS : public FGlobalShader
	{
	public:
		DECLARE_GLOBAL_SHADER(FRecombineCS);
		SHADER_USE_PARAMETER_STRUCT(FRecombineCS, FGlobalShader);

		BEGIN_SHADER_PARAMETER_STRUCT(FParameters, )
			SHADER_PARAMETER_STRUCT_INCLUDE(FCommonParameters, CommonParameters)
			SHADER_PARAMETER_RDG_TEXTURE(Texture2D, ScatteringTexture)
			SHADER_PARAMETER_RDG_TEXTURE(Texture2D, SetupTexture)
			SHADER_PARAMETER_RDG_TEXTURE_UAV(RWTexture2D<float4>, Output)
		END_SHADER_PARAMETER_STRUCT()

		static bool ShouldCompilePermutation(const FGlobalShaderPermutationParameters& Parameters)
		{
			return IsFeatureLevelSupported(Parameters.Platform, ERHIFeatureLevel::SM5);
		}
	};
	IMPLEMENT_GLOBAL_SHADER(FRecombineCS, "/Plugins/ScreenSpaceFogScattering/SSFSRecombine.usf", "RecombineCS", SF_Compute);
}

DECLARE_GPU_STAT_NAMED(SSFS, TEXT("Screen Space Fog Scattering"))

FScreenSpaceFogScatteringViewExtension::FScreenSpaceFogScatteringViewExtension(const FAutoRegister& AutoRegister) : FSceneViewExtensionBase(AutoRegister)
{
	UE_LOG(LogTemp, Log, TEXT("SceneViewExtension: Screen Space Fog Scattering is registered"));
}

// Render the SSFS at the start of the post processing pipeline (before DOF) ensuring that it's compatible with any other default post process effects
void FScreenSpaceFogScatteringViewExtension::PrePostProcessPass_RenderThread(FRDGBuilder& GraphBuilder, const FSceneView& View, const FPostProcessingInputs& Inputs)
{
	FSceneViewExtensionBase::PrePostProcessPass_RenderThread(GraphBuilder, View, Inputs);
	
	const FIntRect Viewport = static_cast<const FViewInfo&>(View).ViewRect;
	const FViewInfo& ViewInfo = static_cast<const FViewInfo&>(View);
	FScreenPassTexture SceneColor((*Inputs.SceneTextures)->SceneColorTexture, Viewport);
	FScreenPassTexture SSFSOutput;

	const int32 MaxPassAmount = 12;
	PassAmount = FMath::Clamp(CVarSSFSPassAmount.GetValueOnRenderThread(), 0, MaxPassAmount);
	const bool Validity = CVarSSFS.GetValueOnRenderThread() == 1 && PassAmount > 1 && CVarSSFSIntensity.GetValueOnRenderThread() > 0 && CVarSSFSRadius.GetValueOnRenderThread() > 0;

	if (SceneColor.IsValid() && Validity)
	{
		RDG_EVENT_SCOPE(GraphBuilder, "ScreenSpaceFogScattering %dx%d (PassAmount=%d)", Viewport.Width(), Viewport.Height(), PassAmount);
		RenderSSFS(GraphBuilder, ViewInfo, Inputs, SSFSOutput);
		AddCopyTexturePass(GraphBuilder, SSFSOutput.Texture, SceneColor.Texture);
	}
}

void FScreenSpaceFogScatteringViewExtension::RenderSSFS(FRDGBuilder& GraphBuilder, const FViewInfo& ViewInfo, const FPostProcessingInputs& Inputs, FScreenPassTexture& Output)
{
	const FIntRect Viewport = ViewInfo.ViewRect;
	FScreenPassTexture SceneColor((*Inputs.SceneTextures)->SceneColorTexture, Viewport);
	FScreenPassTexture SceneDepth((*Inputs.SceneTextures)->SceneDepthTexture, Viewport);
	
	RDG_GPU_STAT_SCOPE(GraphBuilder, SSFS)

	FScreenPassTexture ScatteringTexture;
	
	// Setup
	FRDGTextureRef SetupTexture = Setup(GraphBuilder, ViewInfo, SceneColor.Texture, SceneDepth.Texture, SceneColor.ViewRect);

	// Both Downsample and Upsample methods for rendering Bloom are described here: http://www.iryoku.com/next-generation-post-processing-in-call-of-duty-advanced-warfare
	// You can learn about the Unreal implementation of this in detail here: https://www.froyok.fr/blog/2021-12-ue4-custom-bloom/
	// It's also a perfect fit for the Fog Scattering shader
	{
		RDG_EVENT_SCOPE(GraphBuilder, "SSFS Downsample");
		
		// Downsample
		int32 Width = ViewInfo.ViewRect.Width();
		int32 Height = ViewInfo.ViewRect.Height();
		int32 Divider = 1;
		FRDGTextureRef PreviousTexture = SetupTexture;

		for(int32 i = 0; i < PassAmount; i++)
		{
			FIntRect Size{0,0,FMath::Max(Width / Divider, 2),FMath::Max(Height / Divider, 2)};

			const FString PassName = "Downsample (1/" 
			+ FString::FromInt(Divider)
			+ ") "
			+ FString::FromInt(Size.Width()) + "x"
			+ FString::FromInt(Size.Height());

			const FString* TextureName = GraphBuilder.AllocObject<FString>("SSFS.Downsample(1/" 
			+ FString::FromInt(Divider)
			+ ")");

			FRDGTextureRef Texture = nullptr;
		
			if (i == 0)
			{
				Texture = PreviousTexture;
			}
			else
			{
				Texture = Downsample(GraphBuilder, ViewInfo, PassName, TextureName, PreviousTexture, Size);
			}

			FScreenPassTexture DownsampleTexture(Texture, Size);

			DownsampleMipMaps.Add(DownsampleTexture);
			PreviousTexture = Texture;
			Divider *= 2;
		}
	}

	{
		RDG_EVENT_SCOPE(GraphBuilder, "SSFS Upsample");
	
		// Upsample
		float Radius = CVarSSFSRadius.GetValueOnRenderThread();
		
		UpsampleMipMaps.Append(DownsampleMipMaps);
		
		for(int32 i = PassAmount - 2; i >= 0; i--)
		{
			FIntRect CurrentSize = UpsampleMipMaps[i].ViewRect;
			//FIntRect CurrentSize = UpsampleMipMaps[i].Texture->Desc.Extent.XY;

			const FString PassName  = "Upsample & Combine ("
			+ FString::FromInt(PassAmount - 1 - i)
			+ "/"
			+ FString::FromInt(PassAmount - 1)
			+ ") "
			+ FString::FromInt(CurrentSize.Width())
			+ "x"
			+ FString::FromInt(CurrentSize.Height());

			const FString* TextureName = GraphBuilder.AllocObject<FString>("SSFS.Upsample(" 
			+ FString::FromInt(PassAmount - 1 - i)
			+ "/"
			+ FString::FromInt(PassAmount - 1)
			+ ")"
			);

			FRDGTextureRef ResultTexture = UpsampleCombine(GraphBuilder, ViewInfo, PassName, TextureName, UpsampleMipMaps[i], UpsampleMipMaps[i + 1], Radius);

			FScreenPassTexture NewTexture(ResultTexture, CurrentSize);
			UpsampleMipMaps[i] = NewTexture;
		}

		ScatteringTexture = UpsampleMipMaps[0];
	}

	// Recombine
	FRDGTextureRef CombineTexture = Recombine(GraphBuilder, ViewInfo, SceneColor, ScatteringTexture.Texture, SetupTexture, SceneColor.ViewRect);
	
	// Reset texture lists
	DownsampleMipMaps.Empty();
	UpsampleMipMaps.Empty();

	// Output
	Output.Texture = CombineTexture;
	Output.ViewRect = SceneColor.ViewRect;
}

// Setup pass: SceneColor * HeightFog in RGB, HeightFog in A
FRDGTextureRef FScreenSpaceFogScatteringViewExtension::Setup(FRDGBuilder& GraphBuilder, const FViewInfo& View, FRDGTextureRef InputTexture, FRDGTextureRef DepthTexture, const FIntRect& ViewRect)
{
	FRDGTextureDesc Description = InputTexture->Desc;
	Description.Reset();
	Description.Flags |= TexCreate_UAV;
	Description.Flags &= ~(TexCreate_RenderTargetable | TexCreate_FastVRAM);
	Description.Extent = ViewRect.Size();
	Description.Format = PF_FloatRGBA;
	Description.ClearValue = FClearValueBinding(FLinearColor::Black);
	FRDGTextureRef TargetTexture = GraphBuilder.CreateTexture(Description, TEXT("SSFS.Setup"));

	FGlobalShaderMap* GlobalShaderMap = GetGlobalShaderMap(View.FeatureLevel);
	TShaderMapRef<FSetupCS> ComputeShader(GlobalShaderMap);
	FSetupCS::FParameters* PassParameters = GraphBuilder.AllocParameters<FSetupCS::FParameters>();
	
	FIntRect PassViewSize = View.ViewRect;
	FIntPoint SrcTextureSize = InputTexture->Desc.Extent;

	float Intensity = CVarSSFSIntensity.GetValueOnRenderThread();
	
	PassParameters->CommonParameters.ViewUniformBuffer = View.ViewUniformBuffer;
	PassParameters->CommonParameters.ViewportRect = PassViewSize;
	PassParameters->CommonParameters.ViewportInvSize = FVector2f(1.0f / PassViewSize.Width(), 1.0f / PassViewSize.Height());
	PassParameters->CommonParameters.UVScale = FVector2f(float(PassViewSize.Width()) / float(SrcTextureSize.X), float(PassViewSize.Height()) / float(SrcTextureSize.Y));
	PassParameters->CommonParameters.InputTexture = InputTexture;
	PassParameters->CommonParameters.InputSampler = TStaticSamplerState<SF_Bilinear, AM_Border, AM_Border, AM_Border>::GetRHI();
	
	PassParameters->DepthTexture = DepthTexture;
	PassParameters->Intensity = Intensity;
	PassParameters->ExponentialFogParameters = View.ExponentialFogParameters;
	PassParameters->ExponentialFogParameters2 = View.ExponentialFogParameters2;
	PassParameters->ExponentialFogParameters3 = View.ExponentialFogParameters3;
	PassParameters->FogMaxOpacity = View.FogMaxOpacity;
	PassParameters->VolumetricFogStartDistance = 0.0f;
#if ENGINE_MAJOR_VERSION == 5
#if ENGINE_MINOR_VERSION >= 1
	PassParameters->VolumetricFogStartDistance = View.VolumetricFogStartDistance;
#endif
#endif
	if (View.VolumetricFogResources.IntegratedLightScatteringTexture)
	{
		PassParameters->ApplyVolumetricFog = 1.0f;
		PassParameters->IntegratedLightScattering = View.VolumetricFogResources.IntegratedLightScatteringTexture;
	}
	else
	{
		PassParameters->ApplyVolumetricFog = 0.0f;
#if ENGINE_MAJOR_VERSION == 5
		const FRDGSystemTextures& SystemTextures = FRDGSystemTextures::Get(GraphBuilder);
		PassParameters->IntegratedLightScattering = SystemTextures.VolumetricBlackAlphaOne;
#elif ENGINE_MAJOR_VERSION == 4
		PassParameters->IntegratedLightScattering = GBlackAlpha1VolumeTexture->GetRDG(GraphBuilder);
#endif
	}
	PassParameters->Output = GraphBuilder.CreateUAV(FRDGTextureUAVDesc(TargetTexture));
	
	FIntVector GroupCount = FComputeShaderUtils::GetGroupCount(PassViewSize.Size(), DefaultGroupSize);

	FComputeShaderUtils::AddPass(
		GraphBuilder,
		RDG_EVENT_NAME("SSFS Setup %dx%d", PassViewSize.Width(), PassViewSize.Height()),
		ComputeShader,
		PassParameters,
		GroupCount);

	return TargetTexture;
}

// Scattering 13-tap downsample pass
FRDGTextureRef FScreenSpaceFogScatteringViewExtension::Downsample(FRDGBuilder& GraphBuilder, const FViewInfo& View, const FString& PassName, const FString* TextureName, FRDGTextureRef InputTexture, const FIntRect& ViewRect)
{
	FRDGTextureDesc Description = InputTexture->Desc;
	Description.Reset();
	Description.Flags |= TexCreate_UAV;
	Description.Flags &= ~(TexCreate_RenderTargetable | TexCreate_FastVRAM);
	Description.Extent = ViewRect.Size();
	Description.Format = PF_FloatR11G11B10;
	Description.ClearValue = FClearValueBinding(FLinearColor::Black);
	FRDGTextureRef TargetTexture = GraphBuilder.CreateTexture(Description, **TextureName);

	FGlobalShaderMap* GlobalShaderMap = GetGlobalShaderMap(View.FeatureLevel);
	TShaderMapRef<FDownsampleCS> ComputeShader(GlobalShaderMap);
	FDownsampleCS::FParameters* PassParameters = GraphBuilder.AllocParameters<FDownsampleCS::FParameters>();
	
	FIntRect PassViewSize = View.ViewRect;
	FIntPoint SrcTextureSize = Description.Extent;
	
	PassParameters->CommonParameters.ViewUniformBuffer = View.ViewUniformBuffer;
	PassParameters->CommonParameters.ViewportRect = PassViewSize;
	PassParameters->CommonParameters.ViewportInvSize = FVector2f(1.0f / PassViewSize.Width(), 1.0f / PassViewSize.Height());
	PassParameters->CommonParameters.UVScale = FVector2f(float(PassViewSize.Width()) / float(SrcTextureSize.X), float(PassViewSize.Height()) / float(SrcTextureSize.Y));
	PassParameters->CommonParameters.InputTexture = InputTexture;
	PassParameters->CommonParameters.InputSampler = TStaticSamplerState<SF_Bilinear, AM_Clamp, AM_Clamp, AM_Clamp>::GetRHI();
	
	PassParameters->InputSize = FVector2f(ViewRect.Width(), ViewRect.Height()); // ViewRect.Size()
	PassParameters->Output = GraphBuilder.CreateUAV(FRDGTextureUAVDesc(TargetTexture));
	
	FIntVector GroupCount = FComputeShaderUtils::GetGroupCount(SrcTextureSize, DefaultGroupSize);

	FComputeShaderUtils::AddPass(
		GraphBuilder,
		RDG_EVENT_NAME("%s", *PassName),
		ComputeShader,
		PassParameters,
		GroupCount);

	return TargetTexture;
}

// Scattering 9-tap upsample & combine pass
FRDGTextureRef FScreenSpaceFogScatteringViewExtension::UpsampleCombine(FRDGBuilder& GraphBuilder, const FViewInfo& View, const FString& PassName, const FString* TextureName, const FScreenPassTexture& InputTexture, const FScreenPassTexture& PreviousTexture, float Radius)
{
	FRDGTextureDesc Description = InputTexture.Texture->Desc;
	Description.Reset();
	Description.Flags |= TexCreate_UAV;
	Description.Flags &= ~(TexCreate_RenderTargetable | TexCreate_FastVRAM);
	Description.Extent = InputTexture.ViewRect.Size();
	Description.Format = PF_FloatR11G11B10;
	Description.ClearValue = FClearValueBinding(FLinearColor::Black);
	FRDGTextureRef TargetTexture = GraphBuilder.CreateTexture(Description, **TextureName);

	FGlobalShaderMap* GlobalShaderMap = GetGlobalShaderMap(View.FeatureLevel);
	TShaderMapRef<FUpsampleCombineCS> ComputeShader(GlobalShaderMap);
	FUpsampleCombineCS::FParameters* PassParameters = GraphBuilder.AllocParameters<FUpsampleCombineCS::FParameters>();
	
	FIntRect PassViewSize = View.ViewRect;
	FIntPoint SrcTextureSize = Description.Extent;
	
	PassParameters->CommonParameters.ViewUniformBuffer = View.ViewUniformBuffer;
	PassParameters->CommonParameters.ViewportRect = PassViewSize;
	PassParameters->CommonParameters.ViewportInvSize = FVector2f(1.0f / PassViewSize.Width(), 1.0f / PassViewSize.Height());
	PassParameters->CommonParameters.UVScale = FVector2f(float(PassViewSize.Width()) / float(SrcTextureSize.X), float(PassViewSize.Height()) / float(SrcTextureSize.Y));
	PassParameters->CommonParameters.InputTexture = InputTexture.Texture;
	PassParameters->CommonParameters.InputSampler = TStaticSamplerState<SF_Bilinear, AM_Clamp, AM_Clamp, AM_Clamp>::GetRHI();
	
	PassParameters->PreviousTexture = PreviousTexture.Texture;
	PassParameters->InputSize = FVector2f(PreviousTexture.ViewRect.Width(), PreviousTexture.ViewRect.Height()); // PreviousTexture.ViewRect.Size()
	PassParameters->Radius = Radius;
	PassParameters->Output = GraphBuilder.CreateUAV(FRDGTextureUAVDesc(TargetTexture));
	
	FIntVector GroupCount = FComputeShaderUtils::GetGroupCount(SrcTextureSize, DefaultGroupSize);
	
	FComputeShaderUtils::AddPass(
		GraphBuilder,
		RDG_EVENT_NAME("%s", *PassName),
		ComputeShader,
		PassParameters,
		GroupCount);
	
	return TargetTexture;
}

// Final recombine pass: lerp(SceneColor, ScatteringColor, HeightFog)
FRDGTextureRef FScreenSpaceFogScatteringViewExtension::Recombine(FRDGBuilder& GraphBuilder, const FViewInfo& View, const FScreenPassTexture& SceneColor, FRDGTextureRef ScatteringTexture, FRDGTextureRef SetupTexture, const FIntRect& ViewRect)
{
	FRDGTextureDesc Description = SceneColor.Texture->Desc;
	Description.Reset();
	Description.Flags |= TexCreate_UAV;
	Description.Flags &= ~(TexCreate_RenderTargetable | TexCreate_FastVRAM);
	Description.Extent = SceneColor.Texture->Desc.Extent;
	//Description.Format = PF_FloatRGBA;
	Description.ClearValue = FClearValueBinding(FLinearColor::Black);
	FRDGTextureRef TargetTexture = GraphBuilder.CreateTexture(Description, TEXT("SSFS.Recombine"));

	FGlobalShaderMap* GlobalShaderMap = GetGlobalShaderMap(View.FeatureLevel);
	TShaderMapRef<FRecombineCS> ComputeShader(GlobalShaderMap);
	FRecombineCS::FParameters* PassParameters = GraphBuilder.AllocParameters<FRecombineCS::FParameters>();
	
	FIntRect PassViewSize = ViewRect;
	FIntPoint SrcTextureSize = Description.Extent;
	
	PassParameters->CommonParameters.ViewUniformBuffer = View.ViewUniformBuffer;
	PassParameters->CommonParameters.ViewportRect = PassViewSize;
	PassParameters->CommonParameters.ViewportInvSize = FVector2f(1.0f / PassViewSize.Width(), 1.0f / PassViewSize.Height());
	PassParameters->CommonParameters.UVScale = FVector2f(float(PassViewSize.Width()) / float(SrcTextureSize.X), float(PassViewSize.Height()) / float(SrcTextureSize.Y));
	PassParameters->CommonParameters.InputTexture = SceneColor.Texture;
	PassParameters->CommonParameters.InputSampler = TStaticSamplerState<SF_Bilinear, AM_Clamp, AM_Clamp, AM_Clamp>::GetRHI();
	
	PassParameters->ScatteringTexture = ScatteringTexture;
	PassParameters->SetupTexture = SetupTexture;
	PassParameters->Output = GraphBuilder.CreateUAV(FRDGTextureUAVDesc(TargetTexture));
	
	FIntVector GroupCount = FComputeShaderUtils::GetGroupCount(PassViewSize.Size(), DefaultGroupSize);

	FComputeShaderUtils::AddPass(
		GraphBuilder,
		RDG_EVENT_NAME("SSFS Recombine %dx%d", PassViewSize.Width(), PassViewSize.Height()),
		ComputeShader,
		PassParameters,
		GroupCount);
	
	return TargetTexture;
}
