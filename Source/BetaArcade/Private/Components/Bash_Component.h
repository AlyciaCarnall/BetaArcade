// Author : Ryan Robson T7091365

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Bash_Component.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BETAARCADE_API UBash_Component : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UBash_Component();

	// The speed aka velocity to apply
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Bash")
	float Speed = 3000.0f;

	// The Height to add when bashing
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Bash")
	float ZJumpHeight = 0.1f;
	
	// Duration ?
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Bash")
	float Duration = 1.0f;

	// The Time which we will reset to once using Bash
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Bash")
	float CooldownMaxTimeSeconds = 5.0f;

	// The current time which we will count down to 0
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Bash")
	float CooldownCurrentTimeSeconds = 0.0f;

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
	virtual void TriggerBash();
};
