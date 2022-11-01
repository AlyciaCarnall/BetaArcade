// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "BasePowerup_Component.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UBasePowerup_Component : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UBasePowerup_Component();

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	// The Time which we will reset to once using Bash
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Base Powerup Settings")
		float CooldownMaxTimeSeconds = 10.0f;

	// The current time which we will count down to 0
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Base Powerup Settings")
		float CooldownCurrentTimeSeconds = 0.0f;

	//Return whether timer active.
	UFUNCTION(BlueprintPure, Category = "Base Powerup Settings")
	bool IsPowerupActive();

protected:

	virtual void SetPowerup(bool enable);

	//Cached ref to parent player.
	class APlayerPawn* ParentPlayer;
};