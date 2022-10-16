// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "BasePlayerController.generated.h"

/**
 * 
 */
class ABasePlayerCharacter;

UCLASS()
class ABasePlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	virtual void OnPossess(APawn* aPawn) override;	
};
