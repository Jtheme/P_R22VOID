// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "DLSSLibrary.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UObject;
enum class UDLSSMode : uint8;
enum class UDLSSSupport : uint8;
#ifdef DLSSBLUEPRINT_DLSSLibrary_generated_h
#error "DLSSLibrary.generated.h already included, missing '#pragma once' in DLSSLibrary.h"
#endif
#define DLSSBLUEPRINT_DLSSLibrary_generated_h

#define FID_P_R22VOID_Plugins_Nvidia_DLSS_Source_DLSSBlueprint_Public_DLSSLibrary_h_59_SPARSE_DATA
#define FID_P_R22VOID_Plugins_Nvidia_DLSS_Source_DLSSBlueprint_Public_DLSSLibrary_h_59_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execGetDefaultDLSSMode); \
	DECLARE_FUNCTION(execGetDLSSSharpness); \
	DECLARE_FUNCTION(execSetDLSSSharpness); \
	DECLARE_FUNCTION(execGetDLSSMode); \
	DECLARE_FUNCTION(execSetDLSSMode); \
	DECLARE_FUNCTION(execGetDLSSScreenPercentageRange); \
	DECLARE_FUNCTION(execGetDLSSModeInformation); \
	DECLARE_FUNCTION(execGetSupportedDLSSModes); \
	DECLARE_FUNCTION(execIsDLSSModeSupported); \
	DECLARE_FUNCTION(execIsDLAAEnabled); \
	DECLARE_FUNCTION(execEnableDLAA); \
	DECLARE_FUNCTION(execIsDLSSEnabled); \
	DECLARE_FUNCTION(execEnableDLSS); \
	DECLARE_FUNCTION(execGetDLSSMinimumDriverVersion); \
	DECLARE_FUNCTION(execQueryDLSSSupport); \
	DECLARE_FUNCTION(execIsDLSSSupported);


#define FID_P_R22VOID_Plugins_Nvidia_DLSS_Source_DLSSBlueprint_Public_DLSSLibrary_h_59_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execGetDefaultDLSSMode); \
	DECLARE_FUNCTION(execGetDLSSSharpness); \
	DECLARE_FUNCTION(execSetDLSSSharpness); \
	DECLARE_FUNCTION(execGetDLSSMode); \
	DECLARE_FUNCTION(execSetDLSSMode); \
	DECLARE_FUNCTION(execGetDLSSScreenPercentageRange); \
	DECLARE_FUNCTION(execGetDLSSModeInformation); \
	DECLARE_FUNCTION(execGetSupportedDLSSModes); \
	DECLARE_FUNCTION(execIsDLSSModeSupported); \
	DECLARE_FUNCTION(execIsDLAAEnabled); \
	DECLARE_FUNCTION(execEnableDLAA); \
	DECLARE_FUNCTION(execIsDLSSEnabled); \
	DECLARE_FUNCTION(execEnableDLSS); \
	DECLARE_FUNCTION(execGetDLSSMinimumDriverVersion); \
	DECLARE_FUNCTION(execQueryDLSSSupport); \
	DECLARE_FUNCTION(execIsDLSSSupported);


#define FID_P_R22VOID_Plugins_Nvidia_DLSS_Source_DLSSBlueprint_Public_DLSSLibrary_h_59_ACCESSORS
#define FID_P_R22VOID_Plugins_Nvidia_DLSS_Source_DLSSBlueprint_Public_DLSSLibrary_h_59_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUDLSSLibrary(); \
	friend struct Z_Construct_UClass_UDLSSLibrary_Statics; \
public: \
	DECLARE_CLASS(UDLSSLibrary, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/DLSSBlueprint"), DLSSBLUEPRINT_API) \
	DECLARE_SERIALIZER(UDLSSLibrary)


#define FID_P_R22VOID_Plugins_Nvidia_DLSS_Source_DLSSBlueprint_Public_DLSSLibrary_h_59_INCLASS \
private: \
	static void StaticRegisterNativesUDLSSLibrary(); \
	friend struct Z_Construct_UClass_UDLSSLibrary_Statics; \
public: \
	DECLARE_CLASS(UDLSSLibrary, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/DLSSBlueprint"), DLSSBLUEPRINT_API) \
	DECLARE_SERIALIZER(UDLSSLibrary)


#define FID_P_R22VOID_Plugins_Nvidia_DLSS_Source_DLSSBlueprint_Public_DLSSLibrary_h_59_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	DLSSBLUEPRINT_API UDLSSLibrary(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UDLSSLibrary) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(DLSSBLUEPRINT_API, UDLSSLibrary); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UDLSSLibrary); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	DLSSBLUEPRINT_API UDLSSLibrary(UDLSSLibrary&&); \
	DLSSBLUEPRINT_API UDLSSLibrary(const UDLSSLibrary&); \
public: \
	DLSSBLUEPRINT_API virtual ~UDLSSLibrary();


#define FID_P_R22VOID_Plugins_Nvidia_DLSS_Source_DLSSBlueprint_Public_DLSSLibrary_h_59_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	DLSSBLUEPRINT_API UDLSSLibrary(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	DLSSBLUEPRINT_API UDLSSLibrary(UDLSSLibrary&&); \
	DLSSBLUEPRINT_API UDLSSLibrary(const UDLSSLibrary&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(DLSSBLUEPRINT_API, UDLSSLibrary); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UDLSSLibrary); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UDLSSLibrary) \
	DLSSBLUEPRINT_API virtual ~UDLSSLibrary();


#define FID_P_R22VOID_Plugins_Nvidia_DLSS_Source_DLSSBlueprint_Public_DLSSLibrary_h_55_PROLOG
#define FID_P_R22VOID_Plugins_Nvidia_DLSS_Source_DLSSBlueprint_Public_DLSSLibrary_h_59_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_P_R22VOID_Plugins_Nvidia_DLSS_Source_DLSSBlueprint_Public_DLSSLibrary_h_59_SPARSE_DATA \
	FID_P_R22VOID_Plugins_Nvidia_DLSS_Source_DLSSBlueprint_Public_DLSSLibrary_h_59_RPC_WRAPPERS \
	FID_P_R22VOID_Plugins_Nvidia_DLSS_Source_DLSSBlueprint_Public_DLSSLibrary_h_59_ACCESSORS \
	FID_P_R22VOID_Plugins_Nvidia_DLSS_Source_DLSSBlueprint_Public_DLSSLibrary_h_59_INCLASS \
	FID_P_R22VOID_Plugins_Nvidia_DLSS_Source_DLSSBlueprint_Public_DLSSLibrary_h_59_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_P_R22VOID_Plugins_Nvidia_DLSS_Source_DLSSBlueprint_Public_DLSSLibrary_h_59_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_P_R22VOID_Plugins_Nvidia_DLSS_Source_DLSSBlueprint_Public_DLSSLibrary_h_59_SPARSE_DATA \
	FID_P_R22VOID_Plugins_Nvidia_DLSS_Source_DLSSBlueprint_Public_DLSSLibrary_h_59_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_P_R22VOID_Plugins_Nvidia_DLSS_Source_DLSSBlueprint_Public_DLSSLibrary_h_59_ACCESSORS \
	FID_P_R22VOID_Plugins_Nvidia_DLSS_Source_DLSSBlueprint_Public_DLSSLibrary_h_59_INCLASS_NO_PURE_DECLS \
	FID_P_R22VOID_Plugins_Nvidia_DLSS_Source_DLSSBlueprint_Public_DLSSLibrary_h_59_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> DLSSBLUEPRINT_API UClass* StaticClass<class UDLSSLibrary>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_P_R22VOID_Plugins_Nvidia_DLSS_Source_DLSSBlueprint_Public_DLSSLibrary_h


#define FOREACH_ENUM_UDLSSSUPPORT(op) \
	op(UDLSSSupport::Supported) \
	op(UDLSSSupport::NotSupported) \
	op(UDLSSSupport::NotSupportedIncompatibleHardware) \
	op(UDLSSSupport::NotSupportedDriverOutOfDate) \
	op(UDLSSSupport::NotSupportedOperatingSystemOutOfDate) \
	op(UDLSSSupport::NotSupportedByPlatformAtBuildTime) \
	op(UDLSSSupport::NotSupportedIncompatibleAPICaptureToolActive) 

enum class UDLSSSupport : uint8;
template<> struct TIsUEnumClass<UDLSSSupport> { enum { Value = true }; };
template<> DLSSBLUEPRINT_API UEnum* StaticEnum<UDLSSSupport>();

#define FOREACH_ENUM_UDLSSMODE(op) \
	op(UDLSSMode::Off) \
	op(UDLSSMode::Auto) \
	op(UDLSSMode::UltraQuality) \
	op(UDLSSMode::Quality) \
	op(UDLSSMode::Balanced) \
	op(UDLSSMode::Performance) \
	op(UDLSSMode::UltraPerformance) 

enum class UDLSSMode : uint8;
template<> struct TIsUEnumClass<UDLSSMode> { enum { Value = true }; };
template<> DLSSBLUEPRINT_API UEnum* StaticEnum<UDLSSMode>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
