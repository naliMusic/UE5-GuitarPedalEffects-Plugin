// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "GuitarEffectPlugin/Public/SourceEffects/SourceEffectTremolo.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSourceEffectTremolo() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_USoundEffectSourcePreset();
GUITAREFFECTPLUGIN_API UClass* Z_Construct_UClass_USourceEffectTremoloPreset();
GUITAREFFECTPLUGIN_API UClass* Z_Construct_UClass_USourceEffectTremoloPreset_NoRegister();
GUITAREFFECTPLUGIN_API UScriptStruct* Z_Construct_UScriptStruct_FSourceEffectTremoloSettings();
UPackage* Z_Construct_UPackage__Script_GuitarEffectPlugin();
// End Cross Module References

// Begin ScriptStruct FSourceEffectTremoloSettings
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_SourceEffectTremoloSettings;
class UScriptStruct* FSourceEffectTremoloSettings::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_SourceEffectTremoloSettings.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_SourceEffectTremoloSettings.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FSourceEffectTremoloSettings, (UObject*)Z_Construct_UPackage__Script_GuitarEffectPlugin(), TEXT("SourceEffectTremoloSettings"));
	}
	return Z_Registration_Info_UScriptStruct_SourceEffectTremoloSettings.OuterSingleton;
}
template<> GUITAREFFECTPLUGIN_API UScriptStruct* StaticStruct<FSourceEffectTremoloSettings>()
{
	return FSourceEffectTremoloSettings::StaticStruct();
}
struct Z_Construct_UScriptStruct_FSourceEffectTremoloSettings_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/SourceEffects/SourceEffectTremolo.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LFODepth_MetaData[] = {
		{ "Category", "SourceEffect|Preset" },
		{ "ClampMax", "1.0" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/SourceEffects/SourceEffectTremolo.h" },
		{ "UIMax", "1.0" },
		{ "UIMin", "0.0" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LFORate_MetaData[] = {
		{ "Category", "SourceEffect|Preset" },
		{ "ClampMax", "10.0" },
		{ "ClampMin", "0.1" },
		{ "ModuleRelativePath", "Public/SourceEffects/SourceEffectTremolo.h" },
		{ "UIMax", "10.0" },
		{ "UIMin", "0.1" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_LFODepth;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_LFORate;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FSourceEffectTremoloSettings>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FSourceEffectTremoloSettings_Statics::NewProp_LFODepth = { "LFODepth", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSourceEffectTremoloSettings, LFODepth), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LFODepth_MetaData), NewProp_LFODepth_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FSourceEffectTremoloSettings_Statics::NewProp_LFORate = { "LFORate", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSourceEffectTremoloSettings, LFORate), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LFORate_MetaData), NewProp_LFORate_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FSourceEffectTremoloSettings_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSourceEffectTremoloSettings_Statics::NewProp_LFODepth,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSourceEffectTremoloSettings_Statics::NewProp_LFORate,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSourceEffectTremoloSettings_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FSourceEffectTremoloSettings_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_GuitarEffectPlugin,
	nullptr,
	&NewStructOps,
	"SourceEffectTremoloSettings",
	Z_Construct_UScriptStruct_FSourceEffectTremoloSettings_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSourceEffectTremoloSettings_Statics::PropPointers),
	sizeof(FSourceEffectTremoloSettings),
	alignof(FSourceEffectTremoloSettings),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSourceEffectTremoloSettings_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FSourceEffectTremoloSettings_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FSourceEffectTremoloSettings()
{
	if (!Z_Registration_Info_UScriptStruct_SourceEffectTremoloSettings.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_SourceEffectTremoloSettings.InnerSingleton, Z_Construct_UScriptStruct_FSourceEffectTremoloSettings_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_SourceEffectTremoloSettings.InnerSingleton;
}
// End ScriptStruct FSourceEffectTremoloSettings

// Begin Class USourceEffectTremoloPreset Function SetSettings
struct Z_Construct_UFunction_USourceEffectTremoloPreset_SetSettings_Statics
{
	struct SourceEffectTremoloPreset_eventSetSettings_Parms
	{
		FSourceEffectTremoloSettings InSettings;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Audio|Effects|Tremolo" },
		{ "ModuleRelativePath", "Public/SourceEffects/SourceEffectTremolo.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InSettings_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_InSettings;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USourceEffectTremoloPreset_SetSettings_Statics::NewProp_InSettings = { "InSettings", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SourceEffectTremoloPreset_eventSetSettings_Parms, InSettings), Z_Construct_UScriptStruct_FSourceEffectTremoloSettings, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InSettings_MetaData), NewProp_InSettings_MetaData) }; // 2264276106
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USourceEffectTremoloPreset_SetSettings_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USourceEffectTremoloPreset_SetSettings_Statics::NewProp_InSettings,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USourceEffectTremoloPreset_SetSettings_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USourceEffectTremoloPreset_SetSettings_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USourceEffectTremoloPreset, nullptr, "SetSettings", nullptr, nullptr, Z_Construct_UFunction_USourceEffectTremoloPreset_SetSettings_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USourceEffectTremoloPreset_SetSettings_Statics::PropPointers), sizeof(Z_Construct_UFunction_USourceEffectTremoloPreset_SetSettings_Statics::SourceEffectTremoloPreset_eventSetSettings_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USourceEffectTremoloPreset_SetSettings_Statics::Function_MetaDataParams), Z_Construct_UFunction_USourceEffectTremoloPreset_SetSettings_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_USourceEffectTremoloPreset_SetSettings_Statics::SourceEffectTremoloPreset_eventSetSettings_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USourceEffectTremoloPreset_SetSettings()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USourceEffectTremoloPreset_SetSettings_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USourceEffectTremoloPreset::execSetSettings)
{
	P_GET_STRUCT_REF(FSourceEffectTremoloSettings,Z_Param_Out_InSettings);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetSettings(Z_Param_Out_InSettings);
	P_NATIVE_END;
}
// End Class USourceEffectTremoloPreset Function SetSettings

// Begin Class USourceEffectTremoloPreset
void USourceEffectTremoloPreset::StaticRegisterNativesUSourceEffectTremoloPreset()
{
	UClass* Class = USourceEffectTremoloPreset::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "SetSettings", &USourceEffectTremoloPreset::execSetSettings },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(USourceEffectTremoloPreset);
UClass* Z_Construct_UClass_USourceEffectTremoloPreset_NoRegister()
{
	return USourceEffectTremoloPreset::StaticClass();
}
struct Z_Construct_UClass_USourceEffectTremoloPreset_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "AudioSourceEffect" },
		{ "IncludePath", "SourceEffects/SourceEffectTremolo.h" },
		{ "ModuleRelativePath", "Public/SourceEffects/SourceEffectTremolo.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Settings_MetaData[] = {
		{ "Category", "SourceEffect|Preset" },
		{ "ModuleRelativePath", "Public/SourceEffects/SourceEffectTremolo.h" },
		{ "ShowOnlyInnerProperties", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Settings;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_USourceEffectTremoloPreset_SetSettings, "SetSettings" }, // 956139760
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USourceEffectTremoloPreset>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_USourceEffectTremoloPreset_Statics::NewProp_Settings = { "Settings", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USourceEffectTremoloPreset, Settings), Z_Construct_UScriptStruct_FSourceEffectTremoloSettings, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Settings_MetaData), NewProp_Settings_MetaData) }; // 2264276106
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_USourceEffectTremoloPreset_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USourceEffectTremoloPreset_Statics::NewProp_Settings,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_USourceEffectTremoloPreset_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_USourceEffectTremoloPreset_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_USoundEffectSourcePreset,
	(UObject* (*)())Z_Construct_UPackage__Script_GuitarEffectPlugin,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_USourceEffectTremoloPreset_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_USourceEffectTremoloPreset_Statics::ClassParams = {
	&USourceEffectTremoloPreset::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_USourceEffectTremoloPreset_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_USourceEffectTremoloPreset_Statics::PropPointers),
	0,
	0x001010A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_USourceEffectTremoloPreset_Statics::Class_MetaDataParams), Z_Construct_UClass_USourceEffectTremoloPreset_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_USourceEffectTremoloPreset()
{
	if (!Z_Registration_Info_UClass_USourceEffectTremoloPreset.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_USourceEffectTremoloPreset.OuterSingleton, Z_Construct_UClass_USourceEffectTremoloPreset_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_USourceEffectTremoloPreset.OuterSingleton;
}
template<> GUITAREFFECTPLUGIN_API UClass* StaticClass<USourceEffectTremoloPreset>()
{
	return USourceEffectTremoloPreset::StaticClass();
}
USourceEffectTremoloPreset::USourceEffectTremoloPreset(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(USourceEffectTremoloPreset);
USourceEffectTremoloPreset::~USourceEffectTremoloPreset() {}
// End Class USourceEffectTremoloPreset

// Begin Registration
struct Z_CompiledInDeferFile_FID_SRT_Plugins_UE5_GuitarPedalEffects_Plugin_Source_GuitarEffectPlugin_Public_SourceEffects_SourceEffectTremolo_h_Statics
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FSourceEffectTremoloSettings::StaticStruct, Z_Construct_UScriptStruct_FSourceEffectTremoloSettings_Statics::NewStructOps, TEXT("SourceEffectTremoloSettings"), &Z_Registration_Info_UScriptStruct_SourceEffectTremoloSettings, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FSourceEffectTremoloSettings), 2264276106U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_USourceEffectTremoloPreset, USourceEffectTremoloPreset::StaticClass, TEXT("USourceEffectTremoloPreset"), &Z_Registration_Info_UClass_USourceEffectTremoloPreset, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(USourceEffectTremoloPreset), 3043621166U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_SRT_Plugins_UE5_GuitarPedalEffects_Plugin_Source_GuitarEffectPlugin_Public_SourceEffects_SourceEffectTremolo_h_779026468(TEXT("/Script/GuitarEffectPlugin"),
	Z_CompiledInDeferFile_FID_SRT_Plugins_UE5_GuitarPedalEffects_Plugin_Source_GuitarEffectPlugin_Public_SourceEffects_SourceEffectTremolo_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_SRT_Plugins_UE5_GuitarPedalEffects_Plugin_Source_GuitarEffectPlugin_Public_SourceEffects_SourceEffectTremolo_h_Statics::ClassInfo),
	Z_CompiledInDeferFile_FID_SRT_Plugins_UE5_GuitarPedalEffects_Plugin_Source_GuitarEffectPlugin_Public_SourceEffects_SourceEffectTremolo_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_SRT_Plugins_UE5_GuitarPedalEffects_Plugin_Source_GuitarEffectPlugin_Public_SourceEffects_SourceEffectTremolo_h_Statics::ScriptStructInfo),
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
