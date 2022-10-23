// Author : Ryan Robson T7091365
// Edit's by : Alycia Carnall, Craig Palmer

#include "PlayerPawn.h"
#include "Components/SphereComponent.h"
#include "Components/Shield_Component.h"
#include "Components/Bash_Component.h"
#include "Pickup.h"
#include "ShieldPickup.h"

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

void APlayerPawn::ActivateShield()
{
	if (ShieldComponent)
		ShieldComponent->TriggerShield();
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
	ShieldComponent = CreateDefaultSubobject<UShield_Component>(TEXT("Shield Component"));
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

			//CP - Test as only type of pickup - later to introduce tags.
			if (AShieldPickup* const IsShield = Cast<AShieldPickup>(TestPickup))
			{
				ActivateShield();
			}
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
}

void APlayerPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//CP - Collect pickups in range of collection sphere.
	CollectPickups();
}

