#pragma once

#include "MetasoundNodes/MetasoundTremoloNode.h"

#define LOCTEXT_NAMESPACE "MetasoundStandardNodes_TremoloNode"

namespace Metasound
{
	
	//------------------------------------------------------------------------------------
	// FTremoloOperator
	//------------------------------------------------------------------------------------
	FTremoloOperator::FTremoloOperator(const FOperatorSettings& InSettings,
		const FAudioBufferReadRef& InAudioInput,
		const FFloatReadRef& InLFORate,
		const FFloatReadRef& InLFODepth)
		//const FEnumTremoloReadRef& InTremoloType)
		: AudioInput(InAudioInput)
		, AudioOutput(FAudioBufferWriteRef::CreateNew(InSettings))
		, LFORate(InLFORate)
		, LFODepth(InLFODepth)
		//, TremoloType(InTremoloType)
	{
		TremoloDSPProcessor.Init(InSettings.GetSampleRate());
	}

	//------------------------------------------------------------------------------------
	// GET INPUTS, OUTPUTS and EXECUTE
	//------------------------------------------------------------------------------------

	void FTremoloOperator::BindInputs(FInputVertexInterfaceData& InVertexData)
	{
		using namespace TremoloNode;

		InVertexData.BindReadVertex(METASOUND_GET_PARAM_NAME(InParamNameAudioInput), AudioInput);
		InVertexData.BindReadVertex(METASOUND_GET_PARAM_NAME(InParamNameLFORate), LFORate);
		InVertexData.BindReadVertex(METASOUND_GET_PARAM_NAME(InParamNameLFODepth), LFODepth);
		//InVertexData.BindReadVertex(METASOUND_GET_PARAM_NAME(InParamNameTremoloType), TremoloType);

	}

	void FTremoloOperator::BindOutputs(FOutputVertexInterfaceData& InVertexData)
	{
		using namespace TremoloNode;
		InVertexData.BindWriteVertex(METASOUND_GET_PARAM_NAME(OutParamNameAudio), AudioOutput);
	}

	
	void FTremoloOperator::Execute()
	{
		const float* InputAudio = AudioInput->GetData();
		const int32 NumSamples = AudioInput->Num();
		float* OutputAudio = AudioOutput->GetData();

		TremoloDSPProcessor.SetLFODepth(*LFODepth);
		TremoloDSPProcessor.SetLFORate(*LFORate);

		TremoloDSPProcessor.ProcessAudioBuffer(InputAudio, OutputAudio, NumSamples);
	}


	//------------------------------------------------------------------------------------
	// NODE VERTEX and NODE INFO
	//------------------------------------------------------------------------------------
	const FNodeClassMetadata& FTremoloOperator::GetNodeInfo()
	{
		auto InitNodeInfo = []() -> FNodeClassMetadata
		{
			FNodeClassMetadata Info;

			Info.ClassName = { TEXT("UE"), TEXT("Tremolo"), TEXT("Audio") };
			Info.MajorVersion = 1;
			Info.MinorVersion = 0;
			Info.DisplayName = LOCTEXT("Metasound_TremoloDisplayName", "Tremolo");
			Info.Description = LOCTEXT("Metasound_TremoloNodeDescription", "Applies tremolo (amplitude modulation) effect to the audio input.");
			Info.Author = PluginAuthor;
			Info.PromptIfMissing = PluginNodeMissingPrompt;
			Info.DefaultInterface = GetVertexInterface();
			Info.CategoryHierarchy = { LOCTEXT("Metasound_TremoloNodeCategory", "Effects") };

			return Info;
		};

		static const FNodeClassMetadata Info = InitNodeInfo();

		return Info;
	}

	const FVertexInterface& FTremoloOperator::GetVertexInterface()
	{
		using namespace TremoloNode;
		static const FVertexInterface Interface(
			FInputVertexInterface(
				TInputDataVertex<FAudioBuffer>(METASOUND_GET_PARAM_NAME_AND_METADATA(InParamNameAudioInput)),
				TInputDataVertex<float>(METASOUND_GET_PARAM_NAME_AND_METADATA(InParamNameLFORate), 2.0f),
				TInputDataVertex<float>(METASOUND_GET_PARAM_NAME_AND_METADATA(InParamNameLFODepth), 0.5f)
				//TInputDataVertexModel<FEnumTremoloType>(METASOUND_GET_PARAM_NAME_AND_METADATA(InParamNameTremoloType), static_cast<int32>(SimpleDSP::ETremoloType::wSine))
			),

			FOutputVertexInterface(
				TOutputDataVertex<FAudioBuffer>(METASOUND_GET_PARAM_NAME_AND_METADATA(OutParamNameAudio))
			)
		);

		return Interface;
	}

	TUniquePtr<IOperator> FTremoloOperator::CreateOperator(const FBuildOperatorParams& InParams, FBuildResults& OutResults)
	{
		using namespace TremoloNode;

		//const FDataReferenceCollection& InputCollection = InParams.InputDataReferences;
		//const FInputVertexInterface& InputInterface = GetVertexInterface().GetInputInterface();
		const FInputVertexInterfaceData& InputData = InParams.InputData;

		FAudioBufferReadRef AudioIn = InputData.GetOrConstructDataReadReference<FAudioBuffer>(METASOUND_GET_PARAM_NAME(InParamNameAudioInput), InParams.OperatorSettings);
		FFloatReadRef InLFORate = InputData.GetOrConstructDataReadReference<float>(METASOUND_GET_PARAM_NAME(InParamNameLFORate));
		FFloatReadRef InLFODepth = InputData.GetOrConstructDataReadReference<float>(METASOUND_GET_PARAM_NAME(InParamNameLFODepth));
		//FEnumTremoloReadRef InTremoloType = InputCollection.GetDataReadReferenceOrConstruct<FEnumTremoloType>(METASOUND_GET_PARAM_NAME(InParamNameTremoloType));

		//return MakeUnique<FTremoloOperator>(InParams.OperatorSettings, AudioIn, InLFORate, InLFODepth, InTremoloType);
		return MakeUnique<FTremoloOperator>(InParams.OperatorSettings, AudioIn, InLFORate, InLFODepth);
	}


	//------------------------------------------------------------------------------------
	// FTremoloNode
	//------------------------------------------------------------------------------------
	FTremoloNode::FTremoloNode(const FNodeInitData& InitData)
		: FNodeFacade(InitData.InstanceName, InitData.InstanceID, TFacadeOperatorClass<FTremoloOperator>())
	{

	}


	METASOUND_REGISTER_NODE(FTremoloNode)
}

#undef LOCTEXT_NAMESPACE