#include "SourceEffects/SourceEffectVibrato.h"

void FSourceEffectVibrato::Init(const FSoundEffectSourceInitData& InitData)
{
    bIsActive = true;
    NumChannels = InitData.NumSourceChannels;
    VibratoDSPProcessor.Init();
    VibratoDSPProcessor.SampleRate = InitData.SampleRate;

    VibratoDSPProcessor.delayBufferSamples = (int)(MAX_VIBRATO_DELAY_TIME_IN_MILISECOND * 0.001 * InitData.SampleRate) + 1;
    if (VibratoDSPProcessor.delayBufferSamples < 1)
        VibratoDSPProcessor.delayBufferSamples = 1;

    VibratoDSPProcessor.DelayBuffer.SetNumZeroed(VibratoDSPProcessor.delayBufferSamples, true);
    VibratoDSPProcessor.delayWritePosition = 0;
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