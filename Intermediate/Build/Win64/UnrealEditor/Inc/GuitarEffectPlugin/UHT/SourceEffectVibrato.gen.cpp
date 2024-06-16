// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "GuitarEffectPlugin/Public/SourceEffects/SourceEffectVibrato.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSourceEffectVibrato() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_USoundEffectSourcePreset();
GUITAREFFECTPLUGIN_API UClass* Z_Construct_UClass_USourceEffectVibratoPreset();
GUITAREFFECTPLUGIN_API UClass* Z_Construct_UClass_USourceEffectVibratoPreset_NoRegister();
GUITAREFFECTPLUGIN_API UScriptStruct* Z_Construct_UScriptStruct_FSourceEffectVibratoSettings();
UPackage* Z_Construct_UPackage__Script_GuitarEffectPlugin();
// End Cross Module References

// Begin ScriptStruct FSourceEffectVibratoSettings
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_SourceEffectVibratoSettings;
class UScriptStruct* FSourceEffectVibratoSettings::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_SourceEffectVibratoSettings.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_SourceEffectVibratoSettings.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FSourceEffectVibratoSettings, (UObject*)Z_Construct_UPackage__Script_GuitarEffectPlugin(), TEXT("SourceEffectVibratoSettings"));
	}
	return Z_Registration_Info_UScriptStruct_SourceEffectVibratoSettings.OuterSingleton;
}
template<> GUITAREFFECTPLUGIN_API UScriptStruct* StaticStruct<FSourceEffectVibratoSettings>()
{
	return FSourceEffectVibratoSettings::StaticStruct();
}
struct Z_Construct_UScriptStruct_FSourceEffectVibratoSettings_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/SourceEffects/SourceEffectVibrato.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LFORate_MetaData[] = {
		{ "Category", "SourceEffect|Preset" },
		{ "ClampMax", "10.0" },
		{ "ClampMin", "0.1" },
		{ "ModuleRelativePath", "Public/SourceEffects/SourceEffectVibrato.h" },
		{ "UIMax", "10.0" },
		{ "UIMin", "0.1" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_VibratoWidth_MetaData[] = {
		{ "Category", "SourceEffect|Preset" },
		{ "ClampMax", "50.0" },
		{ "ClampMin", "1.0" },
		{ "ModuleRelativePath", "Public/SourceEffects/SourceEffectVibrato.h" },
		{ "UIMax", "50.0" },
		{ "UIMin", "1.0" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_LFORate;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_VibratoWidth;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FSourceEffectVibratoSettings>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FSourceEffectVibratoSettings_Statics::NewProp_LFORate = { "LFORate", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSourceEffectVibratoSettings, LFORate), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LFORate_MetaData), NewProp_LFORate_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FSourceEffectVibratoSettings_Statics::NewProp_VibratoWidth = { "VibratoWidth", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSourceEffectVibratoSettings, VibratoWidth), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_VibratoWidth_MetaData), NewProp_VibratoWidth_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FSourceEffectVibratoSettings_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSourceEffectVibratoSettings_Statics::NewProp_LFORate,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSourceEffectVibratoSettings_Statics::NewProp_VibratoWidth,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSourceEffectVibratoSettings_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FSourceEffectVibratoSettings_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_GuitarEffectPlugin,
	nullptr,
	&NewStructOps,
	"SourceEffectVibratoSettings",
	Z_Construct_UScriptStruct_FSourceEffectVibratoSettings_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSourceEffectVibratoSettings_Statics::PropPointers),
	sizeof(FSourceEffectVibratoSettings),
	alignof(FSourceEffectVibratoSettings),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSourceEffectVibratoSettings_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FSourceEffectVibratoSettings_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FSourceEffectVibratoSettings()
{
	if (!Z_Registration_Info_UScriptStruct_SourceEffectVibratoSettings.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_SourceEffectVibratoSettings.InnerSingleton, Z_Construct_UScriptStruct_FSourceEffectVibratoSettings_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_SourceEffectVibratoSettings.InnerSingleton;
}
// End ScriptStruct FSourceEffectVibratoSettings

// Begin Class USourceEffectVibratoPreset Function SetSettings
struct Z_Construct_UFunction_USourceEffectVibratoPreset_SetSettings_Statics
{
	struct SourceEffectVibratoPreset_eventSetSettings_Parms
	{
		FSourceEffectVibratoSettings InSettings;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Audio|Effects|Vibrato" },
		{ "ModuleRelativePath", "Public/SourceEffects/SourceEffectVibrato.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InSettings_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_InSettings;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USourceEffectVibratoPreset_SetSettings_Statics::NewProp_InSettings = { "InSettings", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SourceEffectVibratoPreset_eventSetSettings_Parms, InSettings), Z_Construct_UScriptStruct_FSourceEffectVibratoSettings, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InSettings_MetaData), NewProp_InSettings_MetaData) }; // 1988865477
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USourceEffectVibratoPreset_SetSettings_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USourceEffectVibratoPreset_SetSettings_Statics::NewProp_InSettings,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USourceEffectVibratoPreset_SetSettings_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USourceEffectVibratoPreset_SetSettings_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USourceEffectVibratoPreset, nullptr, "SetSettings", nullptr, nullptr, Z_Construct_UFunction_USourceEffectVibratoPreset_SetSettings_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USourceEffectVibratoPreset_SetSettings_Statics::PropPointers), sizeof(Z_Construct_UFunction_USourceEffectVibratoPreset_SetSettings_Statics::SourceEffectVibratoPreset_eventSetSettings_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USourceEffectVibratoPreset_SetSettings_Statics::Function_MetaDataParams), Z_Construct_UFunction_USourceEffectVibratoPreset_SetSettings_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_USourceEffectVibratoPreset_SetSettings_Statics::SourceEffectVibratoPreset_eventSetSettings_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USourceEffectVibratoPreset_SetSettings()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USourceEffectVibratoPreset_SetSettings_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USourceEffectVibratoPreset::execSetSettings)
{
	P_GET_STRUCT_REF(FSourceEffectVibratoSettings,Z_Param_Out_InSettings);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetSettings(Z_Param_Out_InSettings);
	P_NATIVE_END;
}
// End Class USourceEffectVibratoPreset Function SetSettings

// Begin Class USourceEffectVibratoPreset
void USourceEffectVibratoPreset::StaticRegisterNativesUSourceEffectVibratoPreset()
{
	UClass* Class = USourceEffectVibratoPreset::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "SetSettings", &USourceEffectVibratoPreset::execSetSettings },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(USourceEffectVibratoPreset);
UClass* Z_Construct_UClass_USourceEffectVibratoPreset_NoRegister()
{
	return USourceEffectVibratoPreset::StaticClass();
}
struct Z_Construct_UClass_USourceEffectVibratoPreset_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "AudioSourceEffect" },
		{ "IncludePath", "SourceEffects/SourceEffectVibrato.h" },
		{ "ModuleRelativePath", "Public/SourceEffects/SourceEffectVibrato.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Settings_MetaData[] = {
		{ "Category", "SourceEffect|Preset" },
		{ "ModuleRelativePath", "Public/SourceEffects/SourceEffectVibrato.h" },
		{ "ShowOnlyInnerProperties", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Settings;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_USourceEffectVibratoPreset_SetSettings, "SetSettings" }, // 3929496572
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USourceEffectVibratoPreset>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_USourceEffectVibratoPreset_Statics::NewProp_Settings = { "Settings", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USourceEffectVibratoPreset, Settings), Z_Construct_UScriptStruct_FSourceEffectVibratoSettings, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Settings_MetaData), NewProp_Settings_MetaData) }; // 1988865477
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_USourceEffectVibratoPreset_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USourceEffectVibratoPreset_Statics::NewProp_Settings,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_USourceEffectVibratoPreset_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_USourceEffectVibratoPreset_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_USoundEffectSourcePreset,
	(UObject* (*)())Z_Construct_UPackage__Script_GuitarEffectPlugin,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_USourceEffectVibratoPreset_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_USourceEffectVibratoPreset_Statics::ClassParams = {
	&USourceEffectVibratoPreset::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_USourceEffectVibratoPreset_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_USourceEffectVibratoPreset_Statics::PropPointers),
	0,
	0x001010A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_USourceEffectVibratoPreset_Statics::Class_MetaDataParams), Z_Construct_UClass_USourceEffectVibratoPreset_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_USourceEffectVibratoPreset()
{
	if (!Z_Registration_Info_UClass_USourceEffectVibratoPreset.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_USourceEffectVibratoPreset.OuterSingleton, Z_Construct_UClass_USourceEffectVibratoPreset_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_USourceEffectVibratoPreset.OuterSingleton;
}
template<> GUITAREFFECTPLUGIN_API UClass* StaticClass<USourceEffectVibratoPreset>()
{
	return USourceEffectVibratoPreset::StaticClass();
}
USourceEffectVibratoPreset::USourceEffectVibratoPreset(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(USourceEffectVibratoPreset);
USourceEffectVibratoPreset::~USourceEffectVibratoPreset() {}
// End Class USourceEffectVibratoPreset

// Begin Registration
struct Z_CompiledInDeferFile_FID_SRT_Plugins_UE5_GuitarPedalEffects_Plugin_Source_GuitarEffectPlugin_Public_SourceEffects_SourceEffectVibrato_h_Statics
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FSourceEffectVibratoSettings::StaticStruct, Z_Construct_UScriptStruct_FSourceEffectVibratoSettings_Statics::NewStructOps, TEXT("SourceEffectVibratoSettings"), &Z_Registration_Info_UScriptStruct_SourceEffectVibratoSettings, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FSourceEffectVibratoSettings), 1988865477U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_USourceEffectVibratoPreset, USourceEffectVibratoPreset::StaticClass, TEXT("USourceEffectVibratoPreset"), &Z_Registration_Info_UClass_USourceEffectVibratoPreset, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(USourceEffectVibratoPreset), 2838036714U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_SRT_Plugins_UE5_GuitarPedalEffects_Plugin_Source_GuitarEffectPlugin_Public_SourceEffects_SourceEffectVibrato_h_2283428899(TEXT("/Script/GuitarEffectPlugin"),
	Z_CompiledInDeferFile_FID_SRT_Plugins_UE5_GuitarPedalEffects_Plugin_Source_GuitarEffectPlugin_Public_SourceEffects_SourceEffectVibrato_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_SRT_Plugins_UE5_GuitarPedalEffects_Plugin_Source_GuitarEffectPlugin_Public_SourceEffects_SourceEffectVibrato_h_Statics::ClassInfo),
	Z_CompiledInDeferFile_FID_SRT_Plugins_UE5_GuitarPedalEffects_Plugin_Source_GuitarEffectPlugin_Public_SourceEffects_SourceEffectVibrato_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_SRT_Plugins_UE5_GuitarPedalEffects_Plugin_Source_GuitarEffectPlugin_Public_SourceEffects_SourceEffectVibrato_h_Statics::ScriptStructInfo),
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
