// Fill out your copyright notice in the Description page of Project Settings.


#include "Powerup.h"

// Sets default values
APowerup::APowerup()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//All pickups start active.
	bIsActive = true;

	//Create the static mesh component
	PickupMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PickupMesh"));
	RootComponent = PickupMesh;
	PickupMesh->SetSimulatePhysics(true);
}

// Called when the game starts or when spawned
void APowerup::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APowerup::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

bool APowerup::IsActive()
{
	return bIsActive;
}

void APowerup::SetActive(bool NewPickupState)
{
	bIsActive = NewPickupState;

}

void APowerup::WasCollected_Implementation()
{
	// Log debug message
	FString PickupDebugString = GetName();
	UE_LOG(LogClass, Log, TEXT("You have collected %s"), *PickupDebugString);
	//Destroy on picked up.
	Destroy(); 
}

