#pragma once

#include "MetasoundNodes/MetasoundVibratoNode.h"

#define LOCTEXT_NAMESPACE "MetasoundStandardNodes_VibratoNode"

namespace Metasound
{

	//------------------------------------------------------------------------------------
	// FVibratoOperator
	//------------------------------------------------------------------------------------
	FVibratoOperator::FVibratoOperator(const FOperatorSettings& InSettings,
		const FAudioBufferReadRef& InAudioInput,
		const FFloatReadRef& InVibratoWidth,
		const FFloatReadRef& InLFORate
		)
		: AudioInput(InAudioInput)
		, AudioOutput(FAudioBufferWriteRef::CreateNew(InSettings))
		, VibratoWidth(InVibratoWidth)
		, LFORate(InLFORate)
	{
		VibratoDSPProcessor.Init(InSettings.GetSampleRate());
	}

	//------------------------------------------------------------------------------------
	// GET INPUTS, OUTPUTS and EXECUTE
	//------------------------------------------------------------------------------------

	//upgraded to new unreal APIs
	void FVibratoOperator::BindInputs(FInputVertexInterfaceData& InVertexData)
	{
		using namespace VibratoNode;
		
		InVertexData.BindReadVertex(METASOUND_GET_PARAM_NAME(AudioInput), AudioInput);
		InVertexData.BindReadVertex(METASOUND_GET_PARAM_NAME(VibratoWidth), VibratoWidth);
		InVertexData.BindReadVertex(METASOUND_GET_PARAM_NAME(LFORate), LFORate);
	}

	void FVibratoOperator::BindOutputs(FOutputVertexInterfaceData& InVertexData)
	{
		using namespace VibratoNode;
		InVertexData.BindWriteVertex(METASOUND_GET_PARAM_NAME(Audio), AudioOutput);
	}
	


	void FVibratoOperator::Execute()
	{
		const float* InputAudio = AudioInput->GetData();
		const int32 NumSamples = AudioInput->Num();
		float* OutputAudio = AudioOutput->GetData();

		VibratoDSPProcessor.SetVibratoWidth(*VibratoWidth);
		VibratoDSPProcessor.SetLFORate(*LFORate);

		VibratoDSPProcessor.ProcessAudioBuffer(InputAudio, OutputAudio, NumSamples);
	}


	//------------------------------------------------------------------------------------
	// NODE VERTEX and NODE INFO
	//------------------------------------------------------------------------------------
	const FNodeClassMetadata& FVibratoOperator::GetNodeInfo()
	{
		auto InitNodeInfo = []() -> FNodeClassMetadata
		{
			FNodeClassMetadata Info;

			Info.ClassName = { TEXT("UE"), TEXT("Vibrato"), TEXT("Audio") };
			Info.MajorVersion = 1;
			Info.MinorVersion = 0;
			Info.DisplayName = LOCTEXT("Metasound_VibratoDisplayName", "Vibrato");
			Info.Description = LOCTEXT("Metasound_VibratoNodeDescription", "Applies vibrato (modulated delay) effect to the audio input.");
			Info.Author = PluginAuthor;
			Info.PromptIfMissing = PluginNodeMissingPrompt;
			Info.DefaultInterface = GetVertexInterface();
			Info.CategoryHierarchy = { LOCTEXT("Metasound_VibratoNodeCategory", "Effects") };

			return Info;
		};

		static const FNodeClassMetadata Info = InitNodeInfo();

		return Info;
	}

	const FVertexInterface& FVibratoOperator::GetVertexInterface()
	{
		using namespace VibratoNode;
		static const FVertexInterface Interface(
			FInputVertexInterface(
				TInputDataVertex<FAudioBuffer>(METASOUND_GET_PARAM_NAME_AND_METADATA(AudioInput)),
				TInputDataVertex<float>(METASOUND_GET_PARAM_NAME_AND_METADATA(VibratoWidth), 10.0f),
				TInputDataVertex<float>(METASOUND_GET_PARAM_NAME_AND_METADATA(LFORate), 2.0f)
			),

			FOutputVertexInterface(
				TOutputDataVertex<FAudioBuffer>(METASOUND_GET_PARAM_NAME_AND_METADATA(Audio))
			)
		);

		return Interface;
	}

	TUniquePtr<IOperator> FVibratoOperator::CreateOperator(const FBuildOperatorParams& InParams, FBuildResults& OutResults)
	{
		using namespace VibratoNode;

		const FInputVertexInterfaceData& InputData = InParams.InputData;

		FAudioBufferReadRef AudioIn = InputData.GetOrConstructDataReadReference<FAudioBuffer>(METASOUND_GET_PARAM_NAME(AudioInput), InParams.OperatorSettings);
		FFloatReadRef InVibratoWidth = InputData.GetOrConstructDataReadReference<float>(METASOUND_GET_PARAM_NAME(VibratoWidth));
		FFloatReadRef InLFORate = InputData.GetOrConstructDataReadReference<float>(METASOUND_GET_PARAM_NAME(LFORate));
	
		return MakeUnique<FVibratoOperator>(InParams.OperatorSettings, AudioIn, InVibratoWidth, InLFORate);
	}


	//------------------------------------------------------------------------------------
	// FTremoloNode
	//------------------------------------------------------------------------------------
	FVibratoNode::FVibratoNode(const FNodeInitData& InitData)
		: FNodeFacade(InitData.InstanceName, InitData.InstanceID, TFacadeOperatorClass<FVibratoOperator>())
	{
		
	}


	METASOUND_REGISTER_NODE(FVibratoNode)
}

#undef LOCTEXT_NAMESPACE