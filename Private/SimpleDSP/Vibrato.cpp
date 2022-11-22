#pragma once

#include "SimpleDSP/Vibrato.h"

SimpleDSP::FVibrato::FVibrato() : VibratoWidth(10.0f)
								, LFORate(2.0f)
{
}

SimpleDSP::FVibrato::~FVibrato()
{
}

void SimpleDSP::FVibrato::Init()
{
	VibratoLFO.LfoPhase = 0.0f;
}

void SimpleDSP::FVibrato::SetVibratoWidth(float Width)
{
	VibratoWidth = FMath::Clamp(Width, FVibrato::MinVibratoWidth, FVibrato::MaxVibratoWidth) * 0.0001f;
}

void SimpleDSP::FVibrato::SetLFORate(float Rate)
{
	LFORate = FMath::Clamp(Rate, FVibrato::MinLFORate, FVibrato::MaxLFORate);
}

void SimpleDSP::FVibrato::ProcessAudioBuffer(const float* InBuffer, float* OutBuffer, int32 NumSamples)
{
	// Simple DSP and linear interpolation
	float phase		= VibratoLFO.LfoPhase;
	int localWritePosition = delayWritePosition;
	
	for (int32 i = 0; i < NumSamples; ++i)
	{
		float localDelayTime = VibratoWidth * VibratoLFO.Osc(phase, 0) * SampleRate;
		float readPosition = fmodf((float)localWritePosition - localDelayTime + (float)delayBufferSamples - 1.0f, delayBufferSamples);
		int localReadPosition = floorf(readPosition);

		float fraction = readPosition - (float)localReadPosition;
		float d0 = DelayBuffer[(localReadPosition + 0)];
		float d1 = DelayBuffer[(localReadPosition + 1) % delayBufferSamples];

		OutBuffer[i] = d0 + fraction * (d1 - d0);
		DelayBuffer[localWritePosition] = InBuffer[i];

		if (++localWritePosition >= delayBufferSamples)
			localWritePosition -= delayBufferSamples;

		phase += LFORate / SampleRate;
		if (phase >= 1.0f)
			phase -= 1.0f;
	}

	delayWritePosition = localWritePosition;
	VibratoLFO.LfoPhase = phase;
}
