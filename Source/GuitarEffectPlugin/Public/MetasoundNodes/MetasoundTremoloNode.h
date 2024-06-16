#pragma once

#include "MetasoundParamHelper.h"
#include "MetasoundEnumRegistrationMacro.h"
#include "SimpleDSP/Tremolo.h"

namespace Metasound
{

#define LOCTEXT_NAMESPACE "MetasoundStandardNodes_TremoloNode"


	namespace TremoloNode
	{
		METASOUND_PARAM(InParamNameAudioInput, "In", "Audio input.")
		METASOUND_PARAM(InParamNameLFORate, "Rate", "Frequency of the LFO [0.1Hz - 10Hz]. Default is 2Hz.")
		METASOUND_PARAM(InParamNameLFODepth, "Depth", "Intensity of the LFO [0.0 - 1.0]. Default is 0.5")
		//METASOUND_PARAM(InParamNameTremoloType, "Type", "LFO type: Sine, Triangle, Saw, Square")

		METASOUND_PARAM(OutParamNameAudio, "Out", "Audio output.")
	}

	/*DECLARE_METASOUND_ENUM(SimpleDSP::ETremoloType, SimpleDSP::ETremoloType::wSine, GUITAREFFECTPLUGIN_API, FEnumTremoloType, FEnumTremoloTypeInfo, FEnumTremoloReadRef, FEnumTremoloWriteRef);

	DEFINE_METASOUND_ENUM_BEGIN(SimpleDSP::ETremoloType, FEnumTremoloType, "TremoloType")
		DEFINE_METASOUND_ENUM_ENTRY(SimpleDSP::ETremoloType::wSine,		"SineDescription",		"Sine",		"SineLFO",		"Sine LFO Waveform"),
		DEFINE_METASOUND_ENUM_ENTRY(SimpleDSP::ETremoloType::wTriangle,	"TriangleDescription",	"Triangle",	"TriangleLFO",	"Triangle LFO Waveform"),
		DEFINE_METASOUND_ENUM_ENTRY(SimpleDSP::ETremoloType::wSaw,		"SawDescription",		"Saw",		"SawLFO",		"Saw LFO Waveform"),
		DEFINE_METASOUND_ENUM_ENTRY(SimpleDSP::ETremoloType::wSquare,	"SquareDescription",	"Square",	"SquareLFO",	"Square LFO Waveform")
	DEFINE_METASOUND_ENUM_END()*/

#undef LOCTEXT_NAMESPACE

	
	//------------------------------------------------------------------------------------
	// FTremoloOperator
	//------------------------------------------------------------------------------------
	class FTremoloOperator : public TExecutableOperator<FTremoloOperator>
	{
	public:
		static const FNodeClassMetadata& GetNodeInfo();
		static const FVertexInterface& GetVertexInterface();
		static TUniquePtr<IOperator> CreateOperator(const FBuildOperatorParams& InParams, FBuildResults& OutResults);

		FTremoloOperator(const FOperatorSettings& InSettings,
			const FAudioBufferReadRef& InAudioInput,
			const FFloatReadRef& InLFODepth,
			const FFloatReadRef& InLFORate
			//const FEnumTremoloReadRef& InTremoloType
		);

		virtual void BindInputs(FInputVertexInterfaceData& InVertexData) override;
		virtual void BindOutputs(FOutputVertexInterfaceData& InVertexData) override;

		void Execute();


	private:
		// The input audio buffer and audio output
		FAudioBufferReadRef AudioInput;
		FAudioBufferWriteRef AudioOutput;

		// The user-defined settings: rate, depth, type
		FFloatReadRef LFORate;
		FFloatReadRef LFODepth;
		//FEnumTremoloReadRef TremoloType;

		//DSP
		SimpleDSP::FTremolo TremoloDSPProcessor;
	};


	//------------------------------------------------------------------------------------
	// FTremoloNode
	//------------------------------------------------------------------------------------
	class FTremoloNode : public FNodeFacade
	{
	public:
		FTremoloNode(const FNodeInitData& InitData);
	};
}