// DO NOT USE!!!!!!!!!!!!!!

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

	virtual void SetPowerup(bool enable);

	UFUNCTION(BlueprintCallable)
	void DisablePowerUp();

};
