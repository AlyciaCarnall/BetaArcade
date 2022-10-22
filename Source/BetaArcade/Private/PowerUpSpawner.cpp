/*
Author : Craig Palmer V8009358
Location where we're going to spawn Power Ups via the Power Up Manager
*/


#include "Pickup.h"
#include "PowerUpSpawner.h"

// Sets default values
AAPowerUpSpawner::AAPowerUpSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Delay Range
	SpawnDelayRangeLow = 1.0f;
	SpawnDelayRangeHigh = 4.5f;

}

// Called when the game starts or when spawned
void AAPowerUpSpawner::BeginPlay()
{
	Super::BeginPlay();

	SpawnDelay = FMath::RandRange(SpawnDelayRangeLow, SpawnDelayRangeHigh);
	GetWorldTimerManager().SetTimer(SpawnTimer, this, &AAPowerUpSpawner::SpawnPickup, SpawnDelay, false);
	
}

// Called every frame
void AAPowerUpSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AAPowerUpSpawner::SpawnPickup()
{
	//If we have set somewthing to spawn
	if (WhatToSpawn != NULL)
	{
		//Check for valid world
		UWorld* const World = GetWorld();
		if (World)
		{
			//Set spawn parameters
			FActorSpawnParameters SpawnParams;
			SpawnParams.Owner = this;
			SpawnParams.Instigator = GetInstigator();
			FVector SpawnLocation = GetActorLocation();

			//Give random rotation
			FRotator SpawnRotation;
			SpawnRotation.Yaw = FMath::FRand() * 360.0f;
			SpawnRotation.Pitch = FMath::FRand() * 360.0f;
			SpawnRotation.Roll = FMath::FRand() * 360.0f;

			//Spawn the pickup
			World->SpawnActor<APickup>(WhatToSpawn, SpawnLocation, SpawnRotation, SpawnParams);
			
			SpawnDelay = FMath::RandRange(SpawnDelayRangeLow, SpawnDelayRangeHigh);
			GetWorldTimerManager().SetTimer(SpawnTimer, this, &AAPowerUpSpawner::SpawnPickup, SpawnDelay, false);
		}


	}

}

