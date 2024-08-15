#pragma once

#include "MetasoundParamHelper.h"
#include "MetasoundEnumRegistrationMacro.h"
#include "SimpleDSP/Vibrato.h"
#include "DSP/Delay.h"

namespace Metasound
{

#define LOCTEXT_NAMESPACE "MetasoundStandardNodes_VibratoNode"


	namespace VibratoNode
	{
		METASOUND_PARAM(AudioInput, "In", "Audio input.")
		METASOUND_PARAM(VibratoWidth, "Width", "Width of the Vibrato [1.0ms - 50.0ms]. Default is 10ms")
		METASOUND_PARAM(LFORate, "Rate", "Frequency of the LFO [0.1Hz - 10Hz]. Default is 2Hz.")

		METASOUND_PARAM(Audio, "Out", "Audio output.")
	}


#undef LOCTEXT_NAMESPACE


	//------------------------------------------------------------------------------------
	// FVibratoOperator
	//------------------------------------------------------------------------------------
	class FVibratoOperator : public TExecutableOperator<FVibratoOperator>
	{
	public:
		static const FNodeClassMetadata& GetNodeInfo();
		static const FVertexInterface& GetVertexInterface();
		static TUniquePtr<IOperator> CreateOperator(const FBuildOperatorParams& InParams, FBuildResults& OutResults);

		FVibratoOperator(const FOperatorSettings& InSettings,
			const FAudioBufferReadRef& InAudioInput,
			const FFloatReadRef& InVibratoWidth,
			const FFloatReadRef& InLFORate
		);

		virtual void BindInputs(FInputVertexInterfaceData& InVertexData) override;
		virtual void BindOutputs(FOutputVertexInterfaceData& InVertexData) override;

		void Execute();


	private:
		// The input audio buffer, delay buffer and audio output
		FAudioBufferReadRef AudioInput;
		FAudioBufferWriteRef AudioOutput;

		// The user-defined settings: rate, width
		FFloatReadRef VibratoWidth;
		FFloatReadRef LFORate;

		//DSP
		SimpleDSP::FVibrato VibratoDSPProcessor;
	};


	//------------------------------------------------------------------------------------
	// FVibratoNode
	//------------------------------------------------------------------------------------
	class FVibratoNode : public FNodeFacade
	{
	public:
		FVibratoNode(const FNodeInitData& InitData);
	};
}