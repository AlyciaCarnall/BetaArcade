// Author : Ryan Robson T7091365
// Edit's by : Alycia Carnall, Craig Palmer

#include "PlayerPawn.h"
#include "Components/SphereComponent.h"
#include "Pickup.h"

// Sets default values
APlayerPawn::APlayerPawn()
{
	// Setup our components first
	AddComponents();
	SetupComponents();

	PrimaryActorTick.bCanEverTick = true;

	// This should really be from a controller...
	AutoPossessPlayer = EAutoReceiveInput::Player0;
}

void APlayerPawn::MoveForward(float value)
{
	InputDir.X = value;
	
	if(0 == value)
	{
		return;
	}
	else if (nullptr == MeshComponent)
	{
		return;
	}
	
	MeshComponent->AddAngularImpulseInDegrees(FVector::RightVector * value * RollSpeed, NAME_None, true);

	LimitMaximumSpeed();
}

void APlayerPawn::MoveRight(float value)
{
	InputDir.Y = value;
	
	if(0 == value)
	{
		return;
	}
	else if (nullptr == MeshComponent)
	{
		return;
	}
	
	MeshComponent->AddAngularImpulseInDegrees(FVector::ForwardVector * -value * RollSpeed, NAME_None, true);

	LimitMaximumSpeed();
}

void APlayerPawn::Bash()
{
	if(nullptr == BashComponent)
	{
		return;
	}
	
	BashComponent->TriggerBash();
}

void APlayerPawn::Shield()
{
	// Not needed anymore ?
}

void APlayerPawn::Die()
{
	FinishDying();
}

void APlayerPawn::FinishDying()
{
	Destroy();
}

void APlayerPawn::LimitMaximumSpeed() const
{
	FVector const currentVelocity = MeshComponent->ComponentVelocity;
	FVector maxVelocity = (FVector::OneVector * MaximumRollSpeed);
	
	// Check our max speed
	if(currentVelocity.SizeSquared() > maxVelocity.SizeSquared())
	{
		maxVelocity.Z = currentVelocity.Z; // Keep our current Z ?
		MeshComponent->SetPhysicsLinearVelocity(maxVelocity, false, NAME_None);
	}
}

void APlayerPawn::AddComponents()
{
	BashComponent = CreateDefaultSubobject<UBash_Component>(TEXT("Character Bash"));
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Gacha Ball Mesh"));
	PowerupCollectionSphere = CreateDefaultSubobject<USphereComponent>(TEXT("Powerup Collection Sphere"));
}

void APlayerPawn::SetupComponents()
{
	if(MeshComponent != nullptr)
	{
		SetRootComponent(MeshComponent);
		MeshComponent->SetSimulatePhysics(true);
		MeshComponent->SetHiddenInGame(false);
	}

	//CP - Setup Power Up Collection Sphere.
	if (PowerupCollectionSphere != nullptr)
	{
		PowerupCollectionSphere->SetupAttachment(RootComponent);
		PowerupCollectionSphere->SetSphereRadius(200.0f);
	}
}

void APlayerPawn::CollectPickups()
{
	//CP - Collect all actors in range.
	TArray<AActor*> CollectedActors;
	PowerupCollectionSphere->GetOverlappingActors(CollectedActors);

	//CP - Find any of type Pickup by attempting Cast.
	for (AActor* Actor : CollectedActors)
	{
		//CP - Cast to Pickup, not about to be destroyed and is active.
		APickup* const TestPickup = Cast<APickup>(Actor);
		if (TestPickup &&
			!TestPickup->IsPendingKill() &&
			TestPickup->IsActive())
		{
			TestPickup->WasCollected();
			TestPickup->SetActive(false);
		}
	}
}

//RR - This should really be from a controller...
void APlayerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &APlayerPawn::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &APlayerPawn::MoveRight);

	//Actions
	PlayerInputComponent->BindAction("Bash", IE_Pressed, this, &APlayerPawn::Bash);
	PlayerInputComponent->BindAction("Shield", IE_Pressed, this, &APlayerPawn::Shield);
	PlayerInputComponent->BindAction("Shield", IE_Released, this, &APlayerPawn::Shield);
}

void APlayerPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//CP - Collect pickups in range of collection sphere.
	CollectPickups();
}

