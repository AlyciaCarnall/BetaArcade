// Author : Craig Palmer V8009358


#include "PowerupManager.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "PowerUpSpawner.h"
#include "Powerup.h"

// Sets default values
APowerupManager::APowerupManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Delay Range
	SpawnDelayRangeLow = 5.0f;
	SpawnDelayRangeHigh = 10.0f;
}

// Called when the game starts or when spawned
void APowerupManager::BeginPlay()
{
	Super::BeginPlay();
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), APowerUpSpawner::StaticClass(), FoundPowerupPoints);	

	SpawnDelay = FMath::RandRange(SpawnDelayRangeLow, SpawnDelayRangeHigh);
	GetWorldTimerManager().SetTimer(SpawnTimer, this, &APowerupManager::CheckSpawnPickup, SpawnDelay, false);
}

// Called every frame
void APowerupManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void APowerupManager::CheckSpawnPickup()
{
	//Has not been configured correctly.
	if (FoundPowerupPoints.Num() == 0) return;
	if (AvailablePowerups.Num() == 0) return;

	//Set time for next Check Spawn Pikcup
	SpawnDelay = FMath::RandRange(SpawnDelayRangeLow, SpawnDelayRangeHigh);
	GetWorldTimerManager().SetTimer(SpawnTimer, this, &APowerupManager::CheckSpawnPickup, SpawnDelay, false);

	//See if any existing power ups in level, if so just return.
	TArray<AActor*> FoundPowerups;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), APowerup::StaticClass(),FoundPowerups);
	if (FoundPowerups.Num() > 0)
	{
		return;
	}

	//Need to pick a random spot in order to spawn a powerup at.
	UE_LOG(LogClass, Log, TEXT("Spawning Pikcup"));
	const int chosenIndex = FMath::RandRange(0, FoundPowerupPoints.Num());
	const int chosenPickupIndex = FMath::RandRange(0, AvailablePowerups.Num());

	if (FoundPowerupPoints.IsValidIndex(chosenIndex) && AvailablePowerups.IsValidIndex(chosenPickupIndex))
	{
		if (APowerUpSpawner* const ChosenSpawner = Cast<APowerUpSpawner>(FoundPowerupPoints[chosenIndex]))
		{
			ChosenSpawner->SpawnPickup(AvailablePowerups[chosenPickupIndex]);
		}
	}
}


