#include "SourceEffects/SourceEffectVibrato.h"

void FSourceEffectVibrato::Init(const FSoundEffectSourceInitData& InitData)
{
    bIsActive = true;
    NumChannels = InitData.NumSourceChannels;
    VibratoDSPProcessor.Init(InitData.SampleRate);
}

void FSourceEffectVibrato::OnPresetChanged()
{
    GET_EFFECT_SETTINGS(SourceEffectVibrato);
    VibratoDSPProcessor.SetLFORate(Settings.LFORate);
    VibratoDSPProcessor.SetVibratoWidth(Settings.VibratoWidth);
}

void FSourceEffectVibrato::ProcessAudio(const FSoundEffectSourceInputData& InData, float* OutAudioBufferData)
{
    const int32 NumSamples = InData.NumSamples;
    const float* InAudioBuffer = InData.InputSourceEffectBufferPtr;
    float* OutAudioBuffer = OutAudioBufferData;
    VibratoDSPProcessor.ProcessAudioBuffer(InAudioBuffer, OutAudioBuffer, NumSamples);
}

void USourceEffectVibratoPreset::SetSettings(const FSourceEffectVibratoSettings& InSettings)
{
    UpdateSettings(InSettings);
}