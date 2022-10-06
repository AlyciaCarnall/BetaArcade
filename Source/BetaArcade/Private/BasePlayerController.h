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

	bool bShieldActive;
	float fShieldTime;

public:
	ABasePlayerController();
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	void CallMoveRight(float _value);

	UFUNCTION(BlueprintCallable)
	void CallMoveForward(float _value);

	UFUNCTION(BlueprintCallable)
	void CallBash();

	UFUNCTION(BlueprintCallable)
	void CallShield();

	//Character pointer declaration.
	ABasePlayerCharacter* possessedCharacter;
	
};
