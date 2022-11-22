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
	
	class FLfo
	{
	public:
		FLfo();
		virtual ~FLfo();		
		float Osc(float Phase, int WaveType);

		float LfoPhase;
	};
}