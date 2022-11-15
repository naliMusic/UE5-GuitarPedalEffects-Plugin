#pragma once

#include "CoreMinimal.h"

namespace SimpleDSP
{
	enum ETremoloType : int32
	{
		wSine = 0,
		wTriangle,
		wSquare,
		wSaw,
	};
	
	class FTremolo
	{
	public:
		FTremolo();
		virtual ~FTremolo();

		void Init();
		void SetLFODepth(float Depth);
		void SetLFORate(float Rate);
		//void SetTremoloType(ETremoloType InTremoloType);
		void ProcessAudioBuffer(const float* InBuffer, float* OutBuffer, int32 NumSamples);
		float Lfo(float Phase, int WaveType);

		float InverseSampleRate;
		float LfoPhase;
		

	private:
		float LFORate;
		float LFODepth;
		//ETremoloType TremoloType;
		
		const float MaxLFORate = 10.0f;
		const float MinLFORate = 0.1f;
		const float MaxLFODepth = 1.0f;
		const float MinLFODepth = 0.0f;
	};
}