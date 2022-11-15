#include "SimpleDSP/Tremolo.h"


SimpleDSP::FTremolo::FTremolo() : LFODepth(0.5f)
								, LFORate(2.0f)
{
}

SimpleDSP::FTremolo::~FTremolo()
{
}

void SimpleDSP::FTremolo::Init()
{
}

void SimpleDSP::FTremolo::SetLFODepth(float Depth)
{
	LFODepth = FMath::Clamp(Depth, FTremolo::MinLFODepth, FTremolo::MaxLFODepth);
}

void SimpleDSP::FTremolo::SetLFORate(float Rate)
{
	LFORate = FMath::Clamp(Rate, FTremolo::MinLFORate, FTremolo::MaxLFORate);
}

//void SimpleDSP::FTremolo::SetTremoloType(ETremoloType InTremoloType)
//{
//	TremoloType = InTremoloType;
//}

void SimpleDSP::FTremolo::ProcessAudioBuffer(const float* InBuffer, float* OutBuffer, int32 NumSamples)
{
	//Unreal Debug and Insights
	TRACE_CPUPROFILER_EVENT_SCOPE(TEXT("FTremolo::ProcessAudioBuffer"));
//#if UE_BUILD_DEBUG
//	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, “LFO Rate”);
//	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, str(LFORate));
//#endif

	//DSP
	float phase = LfoPhase;
	for (int32 i = 0; i < NumSamples; ++i)
	{
		float modulation = Lfo(phase, 0); //default type sine wave
		OutBuffer[i] = InBuffer[i] * (1 - LFODepth + LFODepth * modulation);

		phase += LFORate * InverseSampleRate;
		if (phase >= 1.0f)
			phase -= 1.0f;
	}

	LfoPhase = phase;
}

float SimpleDSP::FTremolo::Lfo(float Phase, int WaveType)
{
	float result = 0.0f;
	
	//TO-DO: Add more wavetype (default sine)
	switch (WaveType)
	{
		case wSine:
		{
			result = 0.5f * sinf(TWO_PI * Phase) + 0.5f;
			break;
		}

		case wTriangle:
		{
			if (Phase < 0.25f)
				result = 2.0f * Phase + 0.5f;
			else if (Phase < 0.75f)
				result = 1.0f - 2.0f * (Phase - 0.25f);
			else
				result = 2.0f * (Phase - 0.75f);
			break;
		}

		case wSquare:
		{
			if (Phase < 0.5f)
				result = 0.0f;
			else
				result = 1.0f;
			break;
		}

		case wSaw:
		{
			if (Phase < 0.5f)
				result = 0.5f + Phase;
			else
				result = Phase - 0.5f;
			break;
		}
	}
	return result;
}

