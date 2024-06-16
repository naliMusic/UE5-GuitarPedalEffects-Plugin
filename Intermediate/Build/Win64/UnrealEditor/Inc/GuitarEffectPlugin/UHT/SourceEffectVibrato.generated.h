// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "SourceEffects/SourceEffectVibrato.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FSourceEffectVibratoSettings;
#ifdef GUITAREFFECTPLUGIN_SourceEffectVibrato_generated_h
#error "SourceEffectVibrato.generated.h already included, missing '#pragma once' in SourceEffectVibrato.h"
#endif
#define GUITAREFFECTPLUGIN_SourceEffectVibrato_generated_h

#define FID_SRT_Plugins_UE5_GuitarPedalEffects_Plugin_Source_GuitarEffectPlugin_Public_SourceEffects_SourceEffectVibrato_h_31_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FSourceEffectVibratoSettings_Statics; \
	static class UScriptStruct* StaticStruct();


template<> GUITAREFFECTPLUGIN_API UScriptStruct* StaticStruct<struct FSourceEffectVibratoSettings>();

#define FID_SRT_Plugins_UE5_GuitarPedalEffects_Plugin_Source_GuitarEffectPlugin_Public_SourceEffects_SourceEffectVibrato_h_45_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execSetSettings);


#define FID_SRT_Plugins_UE5_GuitarPedalEffects_Plugin_Source_GuitarEffectPlugin_Public_SourceEffects_SourceEffectVibrato_h_45_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUSourceEffectVibratoPreset(); \
	friend struct Z_Construct_UClass_USourceEffectVibratoPreset_Statics; \
public: \
	DECLARE_CLASS(USourceEffectVibratoPreset, USoundEffectSourcePreset, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/GuitarEffectPlugin"), NO_API) \
	DECLARE_SERIALIZER(USourceEffectVibratoPreset)


#define FID_SRT_Plugins_UE5_GuitarPedalEffects_Plugin_Source_GuitarEffectPlugin_Public_SourceEffects_SourceEffectVibrato_h_45_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API USourceEffectVibratoPreset(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	USourceEffectVibratoPreset(USourceEffectVibratoPreset&&); \
	USourceEffectVibratoPreset(const USourceEffectVibratoPreset&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, USourceEffectVibratoPreset); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(USourceEffectVibratoPreset); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(USourceEffectVibratoPreset) \
	NO_API virtual ~USourceEffectVibratoPreset();


#define FID_SRT_Plugins_UE5_GuitarPedalEffects_Plugin_Source_GuitarEffectPlugin_Public_SourceEffects_SourceEffectVibrato_h_42_PROLOG
#define FID_SRT_Plugins_UE5_GuitarPedalEffects_Plugin_Source_GuitarEffectPlugin_Public_SourceEffects_SourceEffectVibrato_h_45_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_SRT_Plugins_UE5_GuitarPedalEffects_Plugin_Source_GuitarEffectPlugin_Public_SourceEffects_SourceEffectVibrato_h_45_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_SRT_Plugins_UE5_GuitarPedalEffects_Plugin_Source_GuitarEffectPlugin_Public_SourceEffects_SourceEffectVibrato_h_45_INCLASS_NO_PURE_DECLS \
	FID_SRT_Plugins_UE5_GuitarPedalEffects_Plugin_Source_GuitarEffectPlugin_Public_SourceEffects_SourceEffectVibrato_h_45_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> GUITAREFFECTPLUGIN_API UClass* StaticClass<class USourceEffectVibratoPreset>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_SRT_Plugins_UE5_GuitarPedalEffects_Plugin_Source_GuitarEffectPlugin_Public_SourceEffects_SourceEffectVibrato_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
