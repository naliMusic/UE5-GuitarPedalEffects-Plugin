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
	FDataReferenceCollection FTremoloOperator::GetInputs() const
	{
		using namespace TremoloNode;

		FDataReferenceCollection InputDataReferences;
		
		InputDataReferences.AddDataReadReference(METASOUND_GET_PARAM_NAME(InParamNameAudioInput), FAudioBufferReadRef(AudioInput));
		InputDataReferences.AddDataReadReference(METASOUND_GET_PARAM_NAME(InParamNameLFORate), FFloatReadRef(LFORate));
		InputDataReferences.AddDataReadReference(METASOUND_GET_PARAM_NAME(InParamNameLFODepth), FFloatReadRef(LFODepth));
		//InputDataReferences.AddDataReadReference(METASOUND_GET_PARAM_NAME(InParamNameTremoloType), FEnumTremoloReadRef(TremoloType));

		return InputDataReferences;
	}

	FDataReferenceCollection FTremoloOperator::GetOutputs() const
	{
		using namespace TremoloNode;

		FDataReferenceCollection OutputDataReferences;
		OutputDataReferences.AddDataReadReference(METASOUND_GET_PARAM_NAME(OutParamNameAudio), FAudioBufferReadRef(AudioOutput));
		return OutputDataReferences;
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
				TInputDataVertexModel<FAudioBuffer>(METASOUND_GET_PARAM_NAME_AND_METADATA(InParamNameAudioInput)),
				TInputDataVertexModel<float>(METASOUND_GET_PARAM_NAME_AND_METADATA(InParamNameLFORate), 2.0f),
				TInputDataVertexModel<float>(METASOUND_GET_PARAM_NAME_AND_METADATA(InParamNameLFODepth), 0.5f)
				//TInputDataVertexModel<FEnumTremoloType>(METASOUND_GET_PARAM_NAME_AND_METADATA(InParamNameTremoloType), static_cast<int32>(SimpleDSP::ETremoloType::wSine))
			),

			FOutputVertexInterface(
				TOutputDataVertexModel<FAudioBuffer>(METASOUND_GET_PARAM_NAME_AND_METADATA(OutParamNameAudio))
			)
		);

		return Interface;
	}

	TUniquePtr<IOperator> FTremoloOperator::CreateOperator(const FCreateOperatorParams& InParams, FBuildErrorArray& OutErrors)
	{
		using namespace TremoloNode;

		const FDataReferenceCollection& InputCollection = InParams.InputDataReferences;
		const FInputVertexInterface& InputInterface = GetVertexInterface().GetInputInterface();

		FAudioBufferReadRef AudioIn = InputCollection.GetDataReadReferenceOrConstruct<FAudioBuffer>(METASOUND_GET_PARAM_NAME(InParamNameAudioInput), InParams.OperatorSettings);
		FFloatReadRef InLFORate = InputCollection.GetDataReadReferenceOrConstructWithVertexDefault<float>(InputInterface, METASOUND_GET_PARAM_NAME(InParamNameLFORate), InParams.OperatorSettings);
		FFloatReadRef InLFODepth = InputCollection.GetDataReadReferenceOrConstructWithVertexDefault<float>(InputInterface, METASOUND_GET_PARAM_NAME(InParamNameLFODepth), InParams.OperatorSettings);
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