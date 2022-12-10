#pragma once

#include "CoreMinimal.h"
#include "LFO.h"

namespace SimpleDSP
{	
	class FTremolo
	{
	public:
		FTremolo();
		virtual ~FTremolo();

		void Init(float sr);
		void SetLFODepth(float Depth);
		void SetLFORate(float Rate);
		//void SetTremoloType(ETremoloType InTremoloType);
		
		void ProcessAudioBuffer(const float* InBuffer, float* OutBuffer, int32 NumSamples);

		float InverseSampleRate;
		
	private:
		SimpleDSP::FLfo TremoloLFO;
		float LFORate;
		float LFODepth;
		
		const float MaxLFORate = 10.0f;
		const float MinLFORate = 0.1f;
		const float MaxLFODepth = 1.0f;
		const float MinLFODepth = 0.0f;
	};
}