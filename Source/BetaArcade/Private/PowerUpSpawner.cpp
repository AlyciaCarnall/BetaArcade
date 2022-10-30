/*
Author : Craig Palmer V8009358
Location where we're going to spawn Power Ups via the Power Up Manager
*/


#include "PowerUpSpawner.h"
#include "Powerup.h"

// Sets default values
APowerUpSpawner::APowerUpSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void APowerUpSpawner::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void APowerUpSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void APowerUpSpawner::SpawnPickup(TSubclassOf<class APowerup> WhatToSpawn)
{
	//If we have set something to spawn
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
			World->SpawnActor<APowerup>(WhatToSpawn, SpawnLocation, SpawnRotation, SpawnParams);


		}
	}
}

