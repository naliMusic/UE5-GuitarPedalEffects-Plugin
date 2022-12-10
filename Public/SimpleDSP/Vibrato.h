#pragma once

#include "CoreMinimal.h"
#include "LFO.h"
#include "DSP/Delay.h"


namespace SimpleDSP
{
#define MAX_VIBRATO_DELAY_TIME_IN_MILISECOND 50.0f

	class FVibrato
	{
	public:
		FVibrato();
		virtual ~FVibrato();

		void Init(float sr);
		void SetVibratoWidth(float Width);
		void SetLFORate(float Rate);
		void ProcessAudioBuffer(const float* InBuffer, float* OutBuffer, int32 NumSamples);

		float SampleRate;

		int delayBufferSamples;
		int delayWritePosition;
		
		Audio::AlignedFloatBuffer DelayBuffer;

	private:
		SimpleDSP::FLfo VibratoLFO;
		float VibratoWidth;
		float LFORate;
		
		const float MaxLFORate = 10.0f;
		const float MinLFORate = 0.1f;
		const float MinVibratoWidth = 1.0f;
		const float MaxVibratoWidth = MAX_VIBRATO_DELAY_TIME_IN_MILISECOND;

	};
}