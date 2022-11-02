// Author : Craig Palmer V8009358

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PowerupManager.generated.h"

UCLASS()
class BETAARCADE_API APowerupManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APowerupManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	FTimerHandle SpawnTimer;

	//Min Spawn Delay
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawning")
	float SpawnDelayRangeLow;
	//Max Spawn Delay
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawning")
	float SpawnDelayRangeHigh;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, Category = "Spawning")
	TArray <TSubclassOf<class APowerup>> AvailablePowerups;

private:

	TArray<AActor*> FoundPowerupPoints; 

	//The current spawn delay
	float SpawnDelay;

	//Iterate cache of pickup points, check if able to spawn pickup.
	void CheckSpawnPickup();

};
