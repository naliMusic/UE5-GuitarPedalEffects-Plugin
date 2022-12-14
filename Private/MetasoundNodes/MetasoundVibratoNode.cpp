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
	FDataReferenceCollection FVibratoOperator::GetInputs() const
	{
		using namespace VibratoNode;

		FDataReferenceCollection InputDataReferences;

		InputDataReferences.AddDataReadReference(METASOUND_GET_PARAM_NAME(InParamNameAudioInput), FAudioBufferReadRef(AudioInput));
		InputDataReferences.AddDataReadReference(METASOUND_GET_PARAM_NAME(InParamNameVibratoWidth), FFloatReadRef(VibratoWidth));
		InputDataReferences.AddDataReadReference(METASOUND_GET_PARAM_NAME(InParamNameLFORate), FFloatReadRef(LFORate));

		return InputDataReferences;
	}

	FDataReferenceCollection FVibratoOperator::GetOutputs() const
	{
		using namespace VibratoNode;

		FDataReferenceCollection OutputDataReferences;
		OutputDataReferences.AddDataReadReference(METASOUND_GET_PARAM_NAME(OutParamNameAudio), FAudioBufferReadRef(AudioOutput));
		return OutputDataReferences;
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
				TInputDataVertexModel<FAudioBuffer>(METASOUND_GET_PARAM_NAME_AND_METADATA(InParamNameAudioInput)),
				TInputDataVertexModel<float>(METASOUND_GET_PARAM_NAME_AND_METADATA(InParamNameVibratoWidth), 10.0f),
				TInputDataVertexModel<float>(METASOUND_GET_PARAM_NAME_AND_METADATA(InParamNameLFORate), 2.0f)
			),

			FOutputVertexInterface(
				TOutputDataVertexModel<FAudioBuffer>(METASOUND_GET_PARAM_NAME_AND_METADATA(OutParamNameAudio))
			)
		);

		return Interface;
	}

	TUniquePtr<IOperator> FVibratoOperator::CreateOperator(const FCreateOperatorParams& InParams, FBuildErrorArray& OutErrors)
	{
		using namespace VibratoNode;

		const FDataReferenceCollection& InputCollection = InParams.InputDataReferences;
		const FInputVertexInterface& InputInterface = GetVertexInterface().GetInputInterface();

		FAudioBufferReadRef AudioIn = InputCollection.GetDataReadReferenceOrConstruct<FAudioBuffer>(METASOUND_GET_PARAM_NAME(InParamNameAudioInput), InParams.OperatorSettings);
		FFloatReadRef InVibratoWidth = InputCollection.GetDataReadReferenceOrConstructWithVertexDefault<float>(InputInterface, METASOUND_GET_PARAM_NAME(InParamNameVibratoWidth), InParams.OperatorSettings);
		FFloatReadRef InLFORate = InputCollection.GetDataReadReferenceOrConstructWithVertexDefault<float>(InputInterface, METASOUND_GET_PARAM_NAME(InParamNameLFORate), InParams.OperatorSettings);
	
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