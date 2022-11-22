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
	TremoloLFO.LfoPhase = 0.0f;
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
	float phase = TremoloLFO.LfoPhase;
	for (int32 i = 0; i < NumSamples; ++i)
	{
		float modulation = TremoloLFO.Osc(phase, 0); //default type sine wave
		OutBuffer[i] = InBuffer[i] * (1 - LFODepth + LFODepth * modulation);

		phase += LFORate * InverseSampleRate;
		if (phase >= 1.0f)
			phase -= 1.0f;
	}

	TremoloLFO.LfoPhase = phase;
}