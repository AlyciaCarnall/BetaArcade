// Author : Ryan Robson T7091365
// Edit's by : Alycia Carnall, Craig Palmer

#include "PlayerPawn.h"
#include "Components/SphereComponent.h"
#include "Components/Bash_Component.h"
#include "Components/Shield_Powerup_Component.h"
#include "Powerup.h"

#include "Kismet/KismetMathLibrary.h"

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
	else if (nullptr == GachaBallMeshComponent)
	{
		return;
	}
	
	GachaBallMeshComponent->AddAngularImpulseInDegrees(FVector::RightVector * value * RollSpeed, NAME_None, true);

	LimitMaximumSpeed();
	OrientCharacter();
}

void APlayerPawn::MoveRight(float value)
{
	InputDir.Y = value;
	
	if(0 == value)
	{
		return;
	}
	else if (nullptr == GachaBallMeshComponent)
	{
		return;
	}
	
	GachaBallMeshComponent->AddAngularImpulseInDegrees(FVector::ForwardVector * -value * RollSpeed, NAME_None, true);

	LimitMaximumSpeed();
	OrientCharacter();
}

void APlayerPawn::Bash()
{
	if(nullptr == BashComponent)
	{
		return;
	}
	
	BashComponent->TriggerBash();
}

void APlayerPawn::ActivatePowerup()
{
	if (ShieldComponent)
		ShieldComponent->SetPowerup(true);
	
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
	FVector const currentVelocity = GachaBallMeshComponent->ComponentVelocity;
	FVector maxVelocity = (FVector::OneVector * MaximumRollSpeed);
	
	// Check our max speed
	if(currentVelocity.SizeSquared() > maxVelocity.SizeSquared())
	{
		maxVelocity.Z = currentVelocity.Z; // Keep our current Z ?
		GachaBallMeshComponent->SetPhysicsLinearVelocity(maxVelocity, false, NAME_None);
	}
}

void APlayerPawn::OrientCharacter()
{
	if(nullptr == CharacterMeshComponent)
	{
		return;
	}

	float yaw { 0 }, pitch { 0 };
	UKismetMathLibrary::GetYawPitchFromVector(FVector(InputDir.X, InputDir.Y, 0.0f), yaw, pitch);
	CharacterMeshComponent->SetWorldRotation(FRotator(0.0f, yaw - 90.0f, 0.0f));
}

void APlayerPawn::RebuildCustomisation()
{
	
}

void APlayerPawn::AddComponents()
{
	BashComponent = CreateDefaultSubobject<UBash_Component>(TEXT("Character Bash"));
	ShieldComponent = CreateDefaultSubobject<UShield_Powerup_Component>(TEXT("Powerup Shield"));
	PowerupCollectionSphere = CreateDefaultSubobject<USphereComponent>(TEXT("Powerup Collection Sphere"));

	GachaBallMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Gacha Ball Mesh"));
	HatMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Hat Mesh"));
}

void APlayerPawn::SetupComponents()
{
	if(nullptr != GachaBallMeshComponent)
	{
		SetRootComponent(GachaBallMeshComponent);
		GachaBallMeshComponent->SetSimulatePhysics(true);
		GachaBallMeshComponent->SetHiddenInGame(false);
	}

	if(nullptr != HatMeshComponent)
	{
		HatMeshComponent->SetupAttachment(RootComponent);
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
		APowerup* const TestPickup = Cast<APowerup>(Actor);
		if (TestPickup &&
			!TestPickup->IsPendingKill() &&
			TestPickup->IsActive())
		{
			TestPickup->WasCollected();
			TestPickup->SetActive(false);

			//CP - Test as only type of pickup - later to introduce tags.
			if (TestPickup->TypeEnum == EPowerupType::PWR_SHIELD)
			{
				ActivatePowerup();
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

