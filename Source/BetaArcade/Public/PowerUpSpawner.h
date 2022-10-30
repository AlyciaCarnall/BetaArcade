/*
Author : Craig Palmer V8009358
Location where we're going to spawn Power Ups via the Power Up Manager
*/

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PowerUpSpawner.generated.h"

UCLASS()
class BETAARCADE_API APowerUpSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APowerUpSpawner();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//Handle Spawning Pickup
	void SpawnPickup(TSubclassOf<class APowerup> WhatToSpawn);
};
