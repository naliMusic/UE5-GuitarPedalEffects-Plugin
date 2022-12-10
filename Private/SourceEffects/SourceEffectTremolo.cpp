#include "SourceEffects/SourceEffectTremolo.h"

void FSourceEffectTremolo::Init(const FSoundEffectSourceInitData& InitData)
{
    bIsActive = true;
    NumChannels = InitData.NumSourceChannels;
    TremoloDSPProcessor.Init(InitData.SampleRate);
}

void FSourceEffectTremolo::OnPresetChanged()
{
    GET_EFFECT_SETTINGS(SourceEffectTremolo);
    TremoloDSPProcessor.SetLFODepth(Settings.LFODepth);
    TremoloDSPProcessor.SetLFORate(Settings.LFORate);
}

void FSourceEffectTremolo::ProcessAudio(const FSoundEffectSourceInputData& InData, float* OutAudioBufferData)
{
    const int32 NumSamples = InData.NumSamples;
    const float* InAudioBuffer = InData.InputSourceEffectBufferPtr;
    float* OutAudioBuffer = OutAudioBufferData;
    TremoloDSPProcessor.ProcessAudioBuffer(InAudioBuffer, OutAudioBuffer, NumSamples);
}

void USourceEffectTremoloPreset::SetSettings(const FSourceEffectTremoloSettings& InSettings)
{
    UpdateSettings(InSettings);
}