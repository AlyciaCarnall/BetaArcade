// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BasePowerup_Component.h"
#include "Shield_Powerup_Component.generated.h"

/**
 * 
 */
UCLASS()
class UShield_Powerup_Component : public UBasePowerup_Component
{
	GENERATED_BODY()

public:
	UShield_Powerup_Component();

	void SetPowerup(bool enable) override;

	
};
