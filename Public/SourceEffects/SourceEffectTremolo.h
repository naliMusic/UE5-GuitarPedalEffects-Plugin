#pragma once

#include "Sound/SoundEffectSource.h"
#include "SimpleDSP/Tremolo.h"
#include "SourceEffectTremolo.generated.h"

class GUITAREFFECTPLUGIN_API FSourceEffectTremolo : public FSoundEffectSource
{
public:
    virtual ~FSourceEffectTremolo() = default;

    // Called on an audio effect at initialization on main thread before audio processing begins.
    virtual void Init(const FSoundEffectSourceInitData& InitData) override;

    // Called when an audio effect preset is changed
    virtual void OnPresetChanged() override;

    // Process the input block of audio. Called on audio thread.
    virtual void ProcessAudio(const FSoundEffectSourceInputData& InData, float* OutAudioBufferData) override;

protected:
    int32 NumChannels = 0;
    SimpleDSP::FTremolo TremoloDSPProcessor;
};



USTRUCT(BlueprintType)
struct GUITAREFFECTPLUGIN_API FSourceEffectTremoloSettings
{
    GENERATED_USTRUCT_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SourceEffect|Preset", meta = (ClampMin = "0.0", ClampMax = "1.0", UIMin = "0.0", UIMax = "1.0"))
    float LFODepth = 0.5f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SourceEffect|Preset", meta = (ClampMin = "0.1", ClampMax = "10.0", UIMin = "0.1", UIMax = "10.0"))
    float LFORate = 2.0f;
};



UCLASS(ClassGroup = AudioSourceEffect, meta = (BlueprintSpawnableComponent))
class GUITAREFFECTPLUGIN_API USourceEffectTremoloPreset : public USoundEffectSourcePreset
{
    GENERATED_BODY()

public:
    EFFECT_PRESET_METHODS(SourceEffectTremolo)

    UFUNCTION(BlueprintCallable, Category = "Audio|Effects|Tremolo")
    void SetSettings(const FSourceEffectTremoloSettings& InSettings);

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "SourceEffect|Preset", Meta = (ShowOnlyInnerProperties))
    FSourceEffectTremoloSettings Settings;
};
