// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "DLSS/Public/DLSSSettings.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeDLSSSettings() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	DLSS_API UClass* Z_Construct_UClass_UDLSSOverrideSettings();
	DLSS_API UClass* Z_Construct_UClass_UDLSSOverrideSettings_NoRegister();
	DLSS_API UClass* Z_Construct_UClass_UDLSSSettings();
	DLSS_API UClass* Z_Construct_UClass_UDLSSSettings_NoRegister();
	DLSS_API UEnum* Z_Construct_UEnum_DLSS_EDLSSSettingOverride();
	UPackage* Z_Construct_UPackage__Script_DLSS();
// End Cross Module References
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_EDLSSSettingOverride;
	static UEnum* EDLSSSettingOverride_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_EDLSSSettingOverride.OuterSingleton)
		{
			Z_Registration_Info_UEnum_EDLSSSettingOverride.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_DLSS_EDLSSSettingOverride, Z_Construct_UPackage__Script_DLSS(), TEXT("EDLSSSettingOverride"));
		}
		return Z_Registration_Info_UEnum_EDLSSSettingOverride.OuterSingleton;
	}
	template<> DLSS_API UEnum* StaticEnum<EDLSSSettingOverride>()
	{
		return EDLSSSettingOverride_StaticEnum();
	}
	struct Z_Construct_UEnum_DLSS_EDLSSSettingOverride_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_DLSS_EDLSSSettingOverride_Statics::Enumerators[] = {
		{ "EDLSSSettingOverride::Enabled", (int64)EDLSSSettingOverride::Enabled },
		{ "EDLSSSettingOverride::Disabled", (int64)EDLSSSettingOverride::Disabled },
		{ "EDLSSSettingOverride::UseProjectSettings", (int64)EDLSSSettingOverride::UseProjectSettings },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_DLSS_EDLSSSettingOverride_Statics::Enum_MetaDataParams[] = {
		{ "Disabled.DisplayName", "False" },
		{ "Disabled.Name", "EDLSSSettingOverride::Disabled" },
		{ "Enabled.DisplayName", "True" },
		{ "Enabled.Name", "EDLSSSettingOverride::Enabled" },
		{ "ModuleRelativePath", "Public/DLSSSettings.h" },
		{ "UseProjectSettings.DisplayName", "Use project settings" },
		{ "UseProjectSettings.Name", "EDLSSSettingOverride::UseProjectSettings" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_DLSS_EDLSSSettingOverride_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_DLSS,
		nullptr,
		"EDLSSSettingOverride",
		"EDLSSSettingOverride",
		Z_Construct_UEnum_DLSS_EDLSSSettingOverride_Statics::Enumerators,
		UE_ARRAY_COUNT(Z_Construct_UEnum_DLSS_EDLSSSettingOverride_Statics::Enumerators),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(Z_Construct_UEnum_DLSS_EDLSSSettingOverride_Statics::Enum_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UEnum_DLSS_EDLSSSettingOverride_Statics::Enum_MetaDataParams))
	};
	UEnum* Z_Construct_UEnum_DLSS_EDLSSSettingOverride()
	{
		if (!Z_Registration_Info_UEnum_EDLSSSettingOverride.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EDLSSSettingOverride.InnerSingleton, Z_Construct_UEnum_DLSS_EDLSSSettingOverride_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_EDLSSSettingOverride.InnerSingleton;
	}
	void UDLSSOverrideSettings::StaticRegisterNativesUDLSSOverrideSettings()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UDLSSOverrideSettings);
	UClass* Z_Construct_UClass_UDLSSOverrideSettings_NoRegister()
	{
		return UDLSSOverrideSettings::StaticClass();
	}
	struct Z_Construct_UClass_UDLSSOverrideSettings_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const UECodeGen_Private::FBytePropertyParams NewProp_EnableDLSSInEditorViewportsOverride_Underlying;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_EnableDLSSInEditorViewportsOverride_MetaData[];
#endif
		static const UECodeGen_Private::FEnumPropertyParams NewProp_EnableDLSSInEditorViewportsOverride;
		static const UECodeGen_Private::FBytePropertyParams NewProp_EnableDLSSInPlayInEditorViewportsOverride_Underlying;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_EnableDLSSInPlayInEditorViewportsOverride_MetaData[];
#endif
		static const UECodeGen_Private::FEnumPropertyParams NewProp_EnableDLSSInPlayInEditorViewportsOverride;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bShowDLSSIncompatiblePluginsToolsWarnings_MetaData[];
#endif
		static void NewProp_bShowDLSSIncompatiblePluginsToolsWarnings_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bShowDLSSIncompatiblePluginsToolsWarnings;
		static const UECodeGen_Private::FBytePropertyParams NewProp_ShowDLSSSDebugOnScreenMessages_Underlying;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ShowDLSSSDebugOnScreenMessages_MetaData[];
#endif
		static const UECodeGen_Private::FEnumPropertyParams NewProp_ShowDLSSSDebugOnScreenMessages;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UDLSSOverrideSettings_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_DLSS,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDLSSOverrideSettings_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "DLSSSettings.h" },
		{ "ModuleRelativePath", "Public/DLSSSettings.h" },
	};
#endif
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UDLSSOverrideSettings_Statics::NewProp_EnableDLSSInEditorViewportsOverride_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDLSSOverrideSettings_Statics::NewProp_EnableDLSSInEditorViewportsOverride_MetaData[] = {
		{ "Category", "Level Editor - Viewport (Local)" },
		{ "Comment", "/** This enables DLSS/DLAA in editor viewports. Saved to local user config only.*/" },
		{ "DisplayName", "Enable DLSS/DLAA to be turned on in Editor viewports" },
		{ "ModuleRelativePath", "Public/DLSSSettings.h" },
		{ "ToolTip", "This enables DLSS/DLAA in editor viewports. Saved to local user config only." },
	};
#endif
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UDLSSOverrideSettings_Statics::NewProp_EnableDLSSInEditorViewportsOverride = { "EnableDLSSInEditorViewportsOverride", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(UDLSSOverrideSettings, EnableDLSSInEditorViewportsOverride), Z_Construct_UEnum_DLSS_EDLSSSettingOverride, METADATA_PARAMS(Z_Construct_UClass_UDLSSOverrideSettings_Statics::NewProp_EnableDLSSInEditorViewportsOverride_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UDLSSOverrideSettings_Statics::NewProp_EnableDLSSInEditorViewportsOverride_MetaData)) }; // 1546296617
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UDLSSOverrideSettings_Statics::NewProp_EnableDLSSInPlayInEditorViewportsOverride_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDLSSOverrideSettings_Statics::NewProp_EnableDLSSInPlayInEditorViewportsOverride_MetaData[] = {
		{ "Category", "Level Editor - Viewport (Local)" },
		{ "Comment", "/** This enables DLSS/DLAA in play in editor viewports. Saved to local user config only. */" },
		{ "DisplayName", "Enable DLSS/DLAA in Play In Editor viewports" },
		{ "ModuleRelativePath", "Public/DLSSSettings.h" },
		{ "ToolTip", "This enables DLSS/DLAA in play in editor viewports. Saved to local user config only." },
	};
#endif
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UDLSSOverrideSettings_Statics::NewProp_EnableDLSSInPlayInEditorViewportsOverride = { "EnableDLSSInPlayInEditorViewportsOverride", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(UDLSSOverrideSettings, EnableDLSSInPlayInEditorViewportsOverride), Z_Construct_UEnum_DLSS_EDLSSSettingOverride, METADATA_PARAMS(Z_Construct_UClass_UDLSSOverrideSettings_Statics::NewProp_EnableDLSSInPlayInEditorViewportsOverride_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UDLSSOverrideSettings_Statics::NewProp_EnableDLSSInPlayInEditorViewportsOverride_MetaData)) }; // 1546296617
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDLSSOverrideSettings_Statics::NewProp_bShowDLSSIncompatiblePluginsToolsWarnings_MetaData[] = {
		{ "Category", "Editor (Local)" },
		{ "Comment", "/** This enables warnings about plugins & tools that are incompatible with DLSS/DLAA in the editor. Saved to local user config only. */" },
		{ "DisplayName", "Warn about incompatible plugins and tools" },
		{ "ModuleRelativePath", "Public/DLSSSettings.h" },
		{ "ToolTip", "This enables warnings about plugins & tools that are incompatible with DLSS/DLAA in the editor. Saved to local user config only." },
	};
#endif
	void Z_Construct_UClass_UDLSSOverrideSettings_Statics::NewProp_bShowDLSSIncompatiblePluginsToolsWarnings_SetBit(void* Obj)
	{
		((UDLSSOverrideSettings*)Obj)->bShowDLSSIncompatiblePluginsToolsWarnings = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UDLSSOverrideSettings_Statics::NewProp_bShowDLSSIncompatiblePluginsToolsWarnings = { "bShowDLSSIncompatiblePluginsToolsWarnings", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(UDLSSOverrideSettings), &Z_Construct_UClass_UDLSSOverrideSettings_Statics::NewProp_bShowDLSSIncompatiblePluginsToolsWarnings_SetBit, METADATA_PARAMS(Z_Construct_UClass_UDLSSOverrideSettings_Statics::NewProp_bShowDLSSIncompatiblePluginsToolsWarnings_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UDLSSOverrideSettings_Statics::NewProp_bShowDLSSIncompatiblePluginsToolsWarnings_MetaData)) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UDLSSOverrideSettings_Statics::NewProp_ShowDLSSSDebugOnScreenMessages_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDLSSOverrideSettings_Statics::NewProp_ShowDLSSSDebugOnScreenMessages_MetaData[] = {
		{ "Category", "Editor (Local)" },
		{ "Comment", "/** This enables on screen warnings and errors about DLSS/DLAA  */" },
		{ "DisplayName", "Show various DLSS/DLAA on screen debug messages" },
		{ "ModuleRelativePath", "Public/DLSSSettings.h" },
		{ "ToolTip", "This enables on screen warnings and errors about DLSS/DLAA" },
	};
#endif
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UDLSSOverrideSettings_Statics::NewProp_ShowDLSSSDebugOnScreenMessages = { "ShowDLSSSDebugOnScreenMessages", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(UDLSSOverrideSettings, ShowDLSSSDebugOnScreenMessages), Z_Construct_UEnum_DLSS_EDLSSSettingOverride, METADATA_PARAMS(Z_Construct_UClass_UDLSSOverrideSettings_Statics::NewProp_ShowDLSSSDebugOnScreenMessages_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UDLSSOverrideSettings_Statics::NewProp_ShowDLSSSDebugOnScreenMessages_MetaData)) }; // 1546296617
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UDLSSOverrideSettings_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDLSSOverrideSettings_Statics::NewProp_EnableDLSSInEditorViewportsOverride_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDLSSOverrideSettings_Statics::NewProp_EnableDLSSInEditorViewportsOverride,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDLSSOverrideSettings_Statics::NewProp_EnableDLSSInPlayInEditorViewportsOverride_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDLSSOverrideSettings_Statics::NewProp_EnableDLSSInPlayInEditorViewportsOverride,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDLSSOverrideSettings_Statics::NewProp_bShowDLSSIncompatiblePluginsToolsWarnings,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDLSSOverrideSettings_Statics::NewProp_ShowDLSSSDebugOnScreenMessages_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDLSSOverrideSettings_Statics::NewProp_ShowDLSSSDebugOnScreenMessages,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UDLSSOverrideSettings_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UDLSSOverrideSettings>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UDLSSOverrideSettings_Statics::ClassParams = {
		&UDLSSOverrideSettings::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UDLSSOverrideSettings_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UDLSSOverrideSettings_Statics::PropPointers),
		0,
		0x001000E4u,
		METADATA_PARAMS(Z_Construct_UClass_UDLSSOverrideSettings_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UDLSSOverrideSettings_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UDLSSOverrideSettings()
	{
		if (!Z_Registration_Info_UClass_UDLSSOverrideSettings.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UDLSSOverrideSettings.OuterSingleton, Z_Construct_UClass_UDLSSOverrideSettings_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UDLSSOverrideSettings.OuterSingleton;
	}
	template<> DLSS_API UClass* StaticClass<UDLSSOverrideSettings>()
	{
		return UDLSSOverrideSettings::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UDLSSOverrideSettings);
	UDLSSOverrideSettings::~UDLSSOverrideSettings() {}
	void UDLSSSettings::StaticRegisterNativesUDLSSSettings()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UDLSSSettings);
	UClass* Z_Construct_UClass_UDLSSSettings_NoRegister()
	{
		return UDLSSSettings::StaticClass();
	}
	struct Z_Construct_UClass_UDLSSSettings_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bEnableDLSSD3D12_MetaData[];
#endif
		static void NewProp_bEnableDLSSD3D12_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bEnableDLSSD3D12;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bEnableDLSSD3D11_MetaData[];
#endif
		static void NewProp_bEnableDLSSD3D11_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bEnableDLSSD3D11;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bEnableDLSSVulkan_MetaData[];
#endif
		static void NewProp_bEnableDLSSVulkan_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bEnableDLSSVulkan;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bEnableDLSSInEditorViewports_MetaData[];
#endif
		static void NewProp_bEnableDLSSInEditorViewports_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bEnableDLSSInEditorViewports;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bEnableDLSSInPlayInEditorViewports_MetaData[];
#endif
		static void NewProp_bEnableDLSSInPlayInEditorViewports_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bEnableDLSSInPlayInEditorViewports;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bShowDLSSSDebugOnScreenMessages_MetaData[];
#endif
		static void NewProp_bShowDLSSSDebugOnScreenMessages_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bShowDLSSSDebugOnScreenMessages;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_GenericDLSSBinaryPath_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_GenericDLSSBinaryPath;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bGenericDLSSBinaryExists_MetaData[];
#endif
		static void NewProp_bGenericDLSSBinaryExists_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bGenericDLSSBinaryExists;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_NVIDIANGXApplicationId_MetaData[];
#endif
		static const UECodeGen_Private::FUInt32PropertyParams NewProp_NVIDIANGXApplicationId;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CustomDLSSBinaryPath_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_CustomDLSSBinaryPath;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bCustomDLSSBinaryExists_MetaData[];
#endif
		static void NewProp_bCustomDLSSBinaryExists_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bCustomDLSSBinaryExists;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UDLSSSettings_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_DLSS,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDLSSSettings_Statics::Class_MetaDataParams[] = {
		{ "DisplayName", "NVIDIA DLSS" },
		{ "IncludePath", "DLSSSettings.h" },
		{ "ModuleRelativePath", "Public/DLSSSettings.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDLSSSettings_Statics::NewProp_bEnableDLSSD3D12_MetaData[] = {
		{ "Category", "Platforms" },
		{ "Comment", "/** Enable DLSS/DLAA for D3D12, if the driver supports it at runtime */" },
		{ "DisplayName", "Enable DLSS/DLAA for the D3D12RHI" },
		{ "ModuleRelativePath", "Public/DLSSSettings.h" },
		{ "ToolTip", "Enable DLSS/DLAA for D3D12, if the driver supports it at runtime" },
	};
#endif
	void Z_Construct_UClass_UDLSSSettings_Statics::NewProp_bEnableDLSSD3D12_SetBit(void* Obj)
	{
		((UDLSSSettings*)Obj)->bEnableDLSSD3D12 = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UDLSSSettings_Statics::NewProp_bEnableDLSSD3D12 = { "bEnableDLSSD3D12", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(UDLSSSettings), &Z_Construct_UClass_UDLSSSettings_Statics::NewProp_bEnableDLSSD3D12_SetBit, METADATA_PARAMS(Z_Construct_UClass_UDLSSSettings_Statics::NewProp_bEnableDLSSD3D12_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UDLSSSettings_Statics::NewProp_bEnableDLSSD3D12_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDLSSSettings_Statics::NewProp_bEnableDLSSD3D11_MetaData[] = {
		{ "Category", "Platforms" },
		{ "Comment", "/** Enable DLSS/DLAA for D3D11, if the driver supports it at runtime */" },
		{ "DisplayName", "Enable DLSS/DLAA for the D3D11RHI" },
		{ "ModuleRelativePath", "Public/DLSSSettings.h" },
		{ "ToolTip", "Enable DLSS/DLAA for D3D11, if the driver supports it at runtime" },
	};
#endif
	void Z_Construct_UClass_UDLSSSettings_Statics::NewProp_bEnableDLSSD3D11_SetBit(void* Obj)
	{
		((UDLSSSettings*)Obj)->bEnableDLSSD3D11 = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UDLSSSettings_Statics::NewProp_bEnableDLSSD3D11 = { "bEnableDLSSD3D11", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(UDLSSSettings), &Z_Construct_UClass_UDLSSSettings_Statics::NewProp_bEnableDLSSD3D11_SetBit, METADATA_PARAMS(Z_Construct_UClass_UDLSSSettings_Statics::NewProp_bEnableDLSSD3D11_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UDLSSSettings_Statics::NewProp_bEnableDLSSD3D11_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDLSSSettings_Statics::NewProp_bEnableDLSSVulkan_MetaData[] = {
		{ "Category", "Platforms" },
		{ "Comment", "/** Enable DLSS/DLAA for Vulkan, if the driver supports it at runtime */" },
		{ "DisplayName", "Enable DLSS/DLAA for the VulkanRHI" },
		{ "ModuleRelativePath", "Public/DLSSSettings.h" },
		{ "ToolTip", "Enable DLSS/DLAA for Vulkan, if the driver supports it at runtime" },
	};
#endif
	void Z_Construct_UClass_UDLSSSettings_Statics::NewProp_bEnableDLSSVulkan_SetBit(void* Obj)
	{
		((UDLSSSettings*)Obj)->bEnableDLSSVulkan = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UDLSSSettings_Statics::NewProp_bEnableDLSSVulkan = { "bEnableDLSSVulkan", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(UDLSSSettings), &Z_Construct_UClass_UDLSSSettings_Statics::NewProp_bEnableDLSSVulkan_SetBit, METADATA_PARAMS(Z_Construct_UClass_UDLSSSettings_Statics::NewProp_bEnableDLSSVulkan_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UDLSSSettings_Statics::NewProp_bEnableDLSSVulkan_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDLSSSettings_Statics::NewProp_bEnableDLSSInEditorViewports_MetaData[] = {
		{ "Category", "Level Editor - Viewport" },
		{ "Comment", "/** This enables DLSS/DLAA in editor viewports. This project wide setting can be locally overridden in the NVIDIA DLSS (Local) settings.*/" },
		{ "DisplayName", "Enable DLSS/DLAA to be turned on in Editor viewports" },
		{ "ModuleRelativePath", "Public/DLSSSettings.h" },
		{ "ToolTip", "This enables DLSS/DLAA in editor viewports. This project wide setting can be locally overridden in the NVIDIA DLSS (Local) settings." },
	};
#endif
	void Z_Construct_UClass_UDLSSSettings_Statics::NewProp_bEnableDLSSInEditorViewports_SetBit(void* Obj)
	{
		((UDLSSSettings*)Obj)->bEnableDLSSInEditorViewports = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UDLSSSettings_Statics::NewProp_bEnableDLSSInEditorViewports = { "bEnableDLSSInEditorViewports", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(UDLSSSettings), &Z_Construct_UClass_UDLSSSettings_Statics::NewProp_bEnableDLSSInEditorViewports_SetBit, METADATA_PARAMS(Z_Construct_UClass_UDLSSSettings_Statics::NewProp_bEnableDLSSInEditorViewports_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UDLSSSettings_Statics::NewProp_bEnableDLSSInEditorViewports_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDLSSSettings_Statics::NewProp_bEnableDLSSInPlayInEditorViewports_MetaData[] = {
		{ "Category", "Level Editor - Viewport" },
		{ "Comment", "/** This enables DLSS/DLAA in play in editor viewports. This project wide setting can be locally overridden in in the NVIDIA DLSS (Local) settings.*/" },
		{ "DisplayName", "Enable DLSS/DLAA in Play In Editor viewports" },
		{ "ModuleRelativePath", "Public/DLSSSettings.h" },
		{ "ToolTip", "This enables DLSS/DLAA in play in editor viewports. This project wide setting can be locally overridden in in the NVIDIA DLSS (Local) settings." },
	};
#endif
	void Z_Construct_UClass_UDLSSSettings_Statics::NewProp_bEnableDLSSInPlayInEditorViewports_SetBit(void* Obj)
	{
		((UDLSSSettings*)Obj)->bEnableDLSSInPlayInEditorViewports = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UDLSSSettings_Statics::NewProp_bEnableDLSSInPlayInEditorViewports = { "bEnableDLSSInPlayInEditorViewports", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(UDLSSSettings), &Z_Construct_UClass_UDLSSSettings_Statics::NewProp_bEnableDLSSInPlayInEditorViewports_SetBit, METADATA_PARAMS(Z_Construct_UClass_UDLSSSettings_Statics::NewProp_bEnableDLSSInPlayInEditorViewports_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UDLSSSettings_Statics::NewProp_bEnableDLSSInPlayInEditorViewports_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDLSSSettings_Statics::NewProp_bShowDLSSSDebugOnScreenMessages_MetaData[] = {
		{ "Category", "Level Editor - Viewport" },
		{ "Comment", "/** This enables on screen warnings and errors about DLSS/DLAA. This project wide setting can be locally overridden in the NVIDIA DLSS (Local) settings. */" },
		{ "DisplayName", "Show various DLSS/DLAA on screen debug messages" },
		{ "ModuleRelativePath", "Public/DLSSSettings.h" },
		{ "ToolTip", "This enables on screen warnings and errors about DLSS/DLAA. This project wide setting can be locally overridden in the NVIDIA DLSS (Local) settings." },
	};
#endif
	void Z_Construct_UClass_UDLSSSettings_Statics::NewProp_bShowDLSSSDebugOnScreenMessages_SetBit(void* Obj)
	{
		((UDLSSSettings*)Obj)->bShowDLSSSDebugOnScreenMessages = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UDLSSSettings_Statics::NewProp_bShowDLSSSDebugOnScreenMessages = { "bShowDLSSSDebugOnScreenMessages", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(UDLSSSettings), &Z_Construct_UClass_UDLSSSettings_Statics::NewProp_bShowDLSSSDebugOnScreenMessages_SetBit, METADATA_PARAMS(Z_Construct_UClass_UDLSSSettings_Statics::NewProp_bShowDLSSSDebugOnScreenMessages_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UDLSSSettings_Statics::NewProp_bShowDLSSSDebugOnScreenMessages_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDLSSSettings_Statics::NewProp_GenericDLSSBinaryPath_MetaData[] = {
		{ "Category", "General Settings" },
		{ "Comment", "/** This is part of the DLSS plugin and used by most projects*/" },
		{ "DisplayName", "Generic DLSS Binary Path" },
		{ "ModuleRelativePath", "Public/DLSSSettings.h" },
		{ "ToolTip", "This is part of the DLSS plugin and used by most projects" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UDLSSSettings_Statics::NewProp_GenericDLSSBinaryPath = { "GenericDLSSBinaryPath", nullptr, (EPropertyFlags)0x0010000000024001, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(UDLSSSettings, GenericDLSSBinaryPath), METADATA_PARAMS(Z_Construct_UClass_UDLSSSettings_Statics::NewProp_GenericDLSSBinaryPath_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UDLSSSettings_Statics::NewProp_GenericDLSSBinaryPath_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDLSSSettings_Statics::NewProp_bGenericDLSSBinaryExists_MetaData[] = {
		{ "Category", "General Settings" },
		{ "DisplayName", "Exists" },
		{ "ModuleRelativePath", "Public/DLSSSettings.h" },
	};
#endif
	void Z_Construct_UClass_UDLSSSettings_Statics::NewProp_bGenericDLSSBinaryExists_SetBit(void* Obj)
	{
		((UDLSSSettings*)Obj)->bGenericDLSSBinaryExists = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UDLSSSettings_Statics::NewProp_bGenericDLSSBinaryExists = { "bGenericDLSSBinaryExists", nullptr, (EPropertyFlags)0x0010000000024001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(UDLSSSettings), &Z_Construct_UClass_UDLSSSettings_Statics::NewProp_bGenericDLSSBinaryExists_SetBit, METADATA_PARAMS(Z_Construct_UClass_UDLSSSettings_Statics::NewProp_bGenericDLSSBinaryExists_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UDLSSSettings_Statics::NewProp_bGenericDLSSBinaryExists_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDLSSSettings_Statics::NewProp_NVIDIANGXApplicationId_MetaData[] = {
		{ "Category", "General Settings" },
		{ "Comment", "/** By default the DLSS plugin uses the UE Project ID to initialize DLSS. In some cases NVIDIA might provide a separate NVIDIA Application ID, which should be put here. Please refer to https://developer.nvidia.com/dlss for details*/" },
		{ "DisplayName", "NVIDIA NGX Application ID" },
		{ "ModuleRelativePath", "Public/DLSSSettings.h" },
		{ "ToolTip", "By default the DLSS plugin uses the UE Project ID to initialize DLSS. In some cases NVIDIA might provide a separate NVIDIA Application ID, which should be put here. Please refer to https://developer.nvidia.com/dlss for details" },
	};
#endif
	const UECodeGen_Private::FUInt32PropertyParams Z_Construct_UClass_UDLSSSettings_Statics::NewProp_NVIDIANGXApplicationId = { "NVIDIANGXApplicationId", nullptr, (EPropertyFlags)0x0010040000004001, UECodeGen_Private::EPropertyGenFlags::UInt32, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(UDLSSSettings, NVIDIANGXApplicationId), METADATA_PARAMS(Z_Construct_UClass_UDLSSSettings_Statics::NewProp_NVIDIANGXApplicationId_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UDLSSSettings_Statics::NewProp_NVIDIANGXApplicationId_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDLSSSettings_Statics::NewProp_CustomDLSSBinaryPath_MetaData[] = {
		{ "Category", "General Settings" },
		{ "Comment", "/** In some cases NVIDIA might provide a project specific DLSS binary for your project. Please refer to https://developer.nvidia.com/dlss for details*/" },
		{ "DisplayName", "Custom DLSS Binary Path" },
		{ "ModuleRelativePath", "Public/DLSSSettings.h" },
		{ "ToolTip", "In some cases NVIDIA might provide a project specific DLSS binary for your project. Please refer to https://developer.nvidia.com/dlss for details" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UDLSSSettings_Statics::NewProp_CustomDLSSBinaryPath = { "CustomDLSSBinaryPath", nullptr, (EPropertyFlags)0x0010040000024001, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(UDLSSSettings, CustomDLSSBinaryPath), METADATA_PARAMS(Z_Construct_UClass_UDLSSSettings_Statics::NewProp_CustomDLSSBinaryPath_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UDLSSSettings_Statics::NewProp_CustomDLSSBinaryPath_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDLSSSettings_Statics::NewProp_bCustomDLSSBinaryExists_MetaData[] = {
		{ "Category", "General Settings" },
		{ "DisplayName", "Exists" },
		{ "ModuleRelativePath", "Public/DLSSSettings.h" },
	};
#endif
	void Z_Construct_UClass_UDLSSSettings_Statics::NewProp_bCustomDLSSBinaryExists_SetBit(void* Obj)
	{
		((UDLSSSettings*)Obj)->bCustomDLSSBinaryExists = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UDLSSSettings_Statics::NewProp_bCustomDLSSBinaryExists = { "bCustomDLSSBinaryExists", nullptr, (EPropertyFlags)0x0010040000024001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(UDLSSSettings), &Z_Construct_UClass_UDLSSSettings_Statics::NewProp_bCustomDLSSBinaryExists_SetBit, METADATA_PARAMS(Z_Construct_UClass_UDLSSSettings_Statics::NewProp_bCustomDLSSBinaryExists_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UDLSSSettings_Statics::NewProp_bCustomDLSSBinaryExists_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UDLSSSettings_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDLSSSettings_Statics::NewProp_bEnableDLSSD3D12,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDLSSSettings_Statics::NewProp_bEnableDLSSD3D11,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDLSSSettings_Statics::NewProp_bEnableDLSSVulkan,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDLSSSettings_Statics::NewProp_bEnableDLSSInEditorViewports,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDLSSSettings_Statics::NewProp_bEnableDLSSInPlayInEditorViewports,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDLSSSettings_Statics::NewProp_bShowDLSSSDebugOnScreenMessages,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDLSSSettings_Statics::NewProp_GenericDLSSBinaryPath,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDLSSSettings_Statics::NewProp_bGenericDLSSBinaryExists,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDLSSSettings_Statics::NewProp_NVIDIANGXApplicationId,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDLSSSettings_Statics::NewProp_CustomDLSSBinaryPath,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDLSSSettings_Statics::NewProp_bCustomDLSSBinaryExists,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UDLSSSettings_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UDLSSSettings>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UDLSSSettings_Statics::ClassParams = {
		&UDLSSSettings::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UDLSSSettings_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UDLSSSettings_Statics::PropPointers),
		0,
		0x001000A6u,
		METADATA_PARAMS(Z_Construct_UClass_UDLSSSettings_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UDLSSSettings_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UDLSSSettings()
	{
		if (!Z_Registration_Info_UClass_UDLSSSettings.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UDLSSSettings.OuterSingleton, Z_Construct_UClass_UDLSSSettings_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UDLSSSettings.OuterSingleton;
	}
	template<> DLSS_API UClass* StaticClass<UDLSSSettings>()
	{
		return UDLSSSettings::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UDLSSSettings);
	UDLSSSettings::~UDLSSSettings() {}
	struct Z_CompiledInDeferFile_FID_P_R22VOID_Plugins_Nvidia_DLSS_Source_DLSS_Public_DLSSSettings_h_Statics
	{
		static const FEnumRegisterCompiledInInfo EnumInfo[];
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FEnumRegisterCompiledInInfo Z_CompiledInDeferFile_FID_P_R22VOID_Plugins_Nvidia_DLSS_Source_DLSS_Public_DLSSSettings_h_Statics::EnumInfo[] = {
		{ EDLSSSettingOverride_StaticEnum, TEXT("EDLSSSettingOverride"), &Z_Registration_Info_UEnum_EDLSSSettingOverride, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1546296617U) },
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_P_R22VOID_Plugins_Nvidia_DLSS_Source_DLSS_Public_DLSSSettings_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UDLSSOverrideSettings, UDLSSOverrideSettings::StaticClass, TEXT("UDLSSOverrideSettings"), &Z_Registration_Info_UClass_UDLSSOverrideSettings, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UDLSSOverrideSettings), 445621193U) },
		{ Z_Construct_UClass_UDLSSSettings, UDLSSSettings::StaticClass, TEXT("UDLSSSettings"), &Z_Registration_Info_UClass_UDLSSSettings, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UDLSSSettings), 337713307U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_P_R22VOID_Plugins_Nvidia_DLSS_Source_DLSS_Public_DLSSSettings_h_2540373166(TEXT("/Script/DLSS"),
		Z_CompiledInDeferFile_FID_P_R22VOID_Plugins_Nvidia_DLSS_Source_DLSS_Public_DLSSSettings_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_P_R22VOID_Plugins_Nvidia_DLSS_Source_DLSS_Public_DLSSSettings_h_Statics::ClassInfo),
		nullptr, 0,
		Z_CompiledInDeferFile_FID_P_R22VOID_Plugins_Nvidia_DLSS_Source_DLSS_Public_DLSSSettings_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_P_R22VOID_Plugins_Nvidia_DLSS_Source_DLSS_Public_DLSSSettings_h_Statics::EnumInfo));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
