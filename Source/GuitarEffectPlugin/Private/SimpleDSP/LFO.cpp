#pragma once

#include "SimpleDSP/LFO.h"

SimpleDSP::FLfo::FLfo() : LfoPhase(0.0f)
{
}

SimpleDSP::FLfo::~FLfo()
{
}

float SimpleDSP::FLfo::Osc(float Phase, int WaveType)
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

