/*
Author : Craig Palmer V8009358
Shield Power up
Allows the player to decrease knock back for 10 seconds
*/

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Shield_Component.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UShield_Component : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UShield_Component();

	// The Time which we will reset to once using Bash
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Shield")
	float CooldownMaxTimeSeconds = 10.0f;

	// The current time which we will count down to 0
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Shield")
	float CooldownCurrentTimeSeconds = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Shield")
	float DampingAmount = 1.0f;

	//Return whether timer active.
	UFUNCTION(BlueprintPure, Category = "Shield")
	bool IsShielded();

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	//Begin shield timer and call Enable Shield
	void TriggerShield();

	//Pass in whether to begin or end shield effect.
	void ToggleShield (bool enable);

private: 
	float LinearDampingCache = 0.0f;

};
