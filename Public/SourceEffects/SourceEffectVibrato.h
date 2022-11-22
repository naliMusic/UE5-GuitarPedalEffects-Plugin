#pragma once

#include "Sound/SoundEffectSource.h"
#include "SimpleDSP/Vibrato.h"
#include "SourceEffectVibrato.generated.h"

class GUITAREFFECTPLUGIN_API FSourceEffectVibrato : public FSoundEffectSource
{
public:
    virtual ~FSourceEffectVibrato() = default;

    // Called on an audio effect at initialization on main thread before audio processing begins.
    virtual void Init(const FSoundEffectSourceInitData& InitData) override;

    // Called when an audio effect preset is changed
    virtual void OnPresetChanged() override;

    // Process the input block of audio. Called on audio thread.
    virtual void ProcessAudio(const FSoundEffectSourceInputData& InData, float* OutAudioBufferData) override;

protected:
    int32 NumChannels = 0;
    SimpleDSP::FVibrato VibratoDSPProcessor;
};



USTRUCT(BlueprintType)
struct GUITAREFFECTPLUGIN_API FSourceEffectVibratoSettings
{
    GENERATED_USTRUCT_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SourceEffect|Preset", meta = (ClampMin = "0.1", ClampMax = "10.0", UIMin = "0.1", UIMax = "10.0"))
        float LFORate = 2.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SourceEffect|Preset", meta = (ClampMin = "1.0", ClampMax = "50.0", UIMin = "1.0", UIMax = "50.0"))
        float VibratoWidth = 10.0f;
};



UCLASS(ClassGroup = AudioSourceEffect, meta = (BlueprintSpawnableComponent))
class GUITAREFFECTPLUGIN_API USourceEffectVibratoPreset : public USoundEffectSourcePreset
{
    GENERATED_BODY()

public:
    EFFECT_PRESET_METHODS(SourceEffectVibrato)

        UFUNCTION(BlueprintCallable, Category = "Audio|Effects|Vibrato")
        void SetSettings(const FSourceEffectVibratoSettings& InSettings);

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "SourceEffect|Preset", Meta = (ShowOnlyInnerProperties))
        FSourceEffectVibratoSettings Settings;
};
