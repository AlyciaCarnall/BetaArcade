/*
Author : Craig Palmer V8009358
Location where we're going to spawn Power Ups via the Power Up Manager
*/

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PowerUpSpawner.generated.h"

UCLASS()
class BETAARCADE_API AAPowerUpSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAPowerUpSpawner();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	//The pickup to spawn
	UPROPERTY(EditAnywhere, Category = "Spawning")
	TSubclassOf<class APickup> WhatToSpawn;

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

private:
	//Handle Spawning Pickup
	void SpawnPickup();
	//The current spawn delay
	float SpawnDelay;

};
