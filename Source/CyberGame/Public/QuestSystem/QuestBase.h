// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "QuestBase.generated.h"

UENUM(BlueprintType)
enum class EQuestType : uint8
{
	Main		UMETA(DisplayName = "Main"),
	Optional	UMETA(DisplayName = "Optional")
};

UENUM(BlueprintType)
enum class EObjectiveType : uint8
{
	Location		UMETA(DisplayName = "Location"),
	Interaction		UMETA(DisplayName = "Interaction"),
	Collect			UMETA(DisplayName = "Collect")
};

USTRUCT(BlueprintType)
struct CYBERGAME_API FObjectiveDetails
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText ObjectiveName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText ObjectiveDescription;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EObjectiveType ObjectiveType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ObjectiveID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Quantity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsOptional;
};

USTRUCT(BlueprintType)
struct CYBERGAME_API FStageDetails
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText StageName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText StageDescription;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FObjectiveDetails> Objectives;
};

USTRUCT(BlueprintType)
struct CYBERGAME_API FQuestDetails
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText QuestName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText LogDescription;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText TrackingDescription;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EQuestType QuestType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FStageDetails> Stages;
};

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType)
class CYBERGAME_API UQuestBase : public UObject
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName QuestID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FQuestDetails QuestDetails;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 CurrentStage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FStageDetails CurrentStageDetails;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<FString, int32> CurrentObjectiveDetails;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsCompleted;
};
