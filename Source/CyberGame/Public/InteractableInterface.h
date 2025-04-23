// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "InteractableInterface.generated.h"

UINTERFACE(MinimalAPI)
class UInteractableInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class CYBERGAME_API IInteractableInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "CyberGame|Interaction")
	void Interact(AActor* Instigator);
	virtual void Interact_Implementation(AActor* Instigator) {}

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "CyberGame|Interaction")
	void CancelInteraction(AActor* Instigator);
	virtual void CancelInteraction_Implementation(AActor* Instigator) {}

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "CyberGame|Interaction")
	bool CanInteract(AActor* Instigator) const;
	virtual bool CanActivate_Interact(AActor* Instigator) const { return false; }

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "CyberGame|Interaction")
	void Focus(AActor* Instigator);
	virtual void Focus_Implementation(AActor* Instigator) {}

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "CyberGame|Interaction")
	void Defocus(AActor* Instigator);
	virtual void Defocus_Implementation(AActor* Instigator) {}

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "CyberGame|Interaction")
	FText GetInteractionMessage(AActor* Instigator) const;
	virtual FText GetInteractionMessage_Interact(AActor* Instigator) const { return FText(); }
};
