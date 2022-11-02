// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BasePowerup_Component.h"
#include "PowerUp_Shield_Component.generated.h"

/**
 * 
 */
UCLASS()
class UPowerUp_Shield_Component : public UBasePowerup_Component
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Powerup Settings")
		float DampingAmount = 1.0f;

	// Called every frame

	UPowerUp_Shield_Component();

	void SetPowerup(bool enable) override;

private:

	float LinearDampingCache = 0.0f;
	
};
