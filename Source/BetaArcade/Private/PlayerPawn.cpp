// Author : Ryan Robson T7091365
// Edit's by : Alycia Carnall, Craig Palmer

#include "PlayerPawn.h"

#include "BaseGameInstance.h"
#include "Components/SphereComponent.h"
#include "Components/Bash_Component.h"
#include "Components/Shield_Powerup_Component.h"
#include "Powerup.h"
#include "Kismet/GameplayStatics.h"

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

	GachaBallMeshComponent->OnComponentBeginOverlap.AddDynamic(this, &APlayerPawn::OnOverlapBegin);
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
	//CP - Call OnBashEvent is successfully Bashed.
	if (BashComponent && BashComponent->TriggerBash())
		OnBash();
}

void APlayerPawn::ActivateShieldPowerup()
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
	if(nullptr == CharacterChildComponent)
	{
		return;
	}

	float yaw { 0 }, pitch { 0 };
	UKismetMathLibrary::GetYawPitchFromVector(FVector(InputDir.X, InputDir.Y, 0.0f), yaw, pitch);
	CharacterChildComponent->SetWorldRotation(FRotator(0.0f, yaw - 90.0f, 0.0f));
}

void APlayerPawn::RebuildCustomisation()
{
	UBaseGameInstance const * const GI = Cast<UBaseGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));
	
	if(nullptr != GachaBallChildComponent)
	{
		if(nullptr != GI)
		{
			GachaBallChildComponent->SetChildActorClass(GI->GetPlayerGachaBallActor(PlayerID));
		}
	}
	
	if(nullptr != HatChildComponent)
	{
		if(nullptr != GI)
		{
			HatChildComponent->SetChildActorClass(GI->GetPlayerHatActor(PlayerID));
		}
	}
	
	if(nullptr != CharacterChildComponent)
	{
		if(nullptr != GI)
		{
			CharacterChildComponent->SetChildActorClass(GI->GetPlayerCharacterActor(PlayerID));
		}
	}

	if (ShieldComponent)ShieldComponent->SetPowerup(true);
}

void APlayerPawn::AddComponents()
{
	//D11.CP - Power up Components
	{
		TwoTimesScoreComponent = CreateDefaultSubobject<UBasePowerup_Component>(TEXT("Two Times Score"));
		AddScoreComponent = CreateDefaultSubobject<UBasePowerup_Component>(TEXT("Add Points Score"));
		PowerupCollectionSphere = CreateDefaultSubobject<USphereComponent>(TEXT("Powerup Collection Sphere"));
		ShieldComponent = CreateDefaultSubobject<UShield_Powerup_Component>(TEXT("Shield"));
	}

	// Base Components
	{
		GachaBallMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Gacha Ball Mesh"));
		BashComponent = CreateDefaultSubobject<UBash_Component>(TEXT("Character Bash"));
	}

	// Customisation
	{
		GachaBallChildComponent = CreateDefaultSubobject<UChildActorComponent>(TEXT("Gacha Ball Child"));
		HatChildComponent = CreateDefaultSubobject<UChildActorComponent>(TEXT("Hat Child"));
		CharacterChildComponent = CreateDefaultSubobject<UChildActorComponent>(TEXT("Character Child"));

		if(nullptr == CustomisationPivot)
		{
			CustomisationPivot = CreateDefaultSubobject<USceneComponent>(TEXT("Customisation Pivot"));
			CustomisationPivot->bEditableWhenInherited = true;
		}

		if(nullptr == GachaBallPivot)
		{
			GachaBallPivot = CreateDefaultSubobject<USceneComponent>(TEXT("Gacha Ball Pivot"));
			GachaBallPivot->bEditableWhenInherited = true;
		}
		
		if(nullptr == CharacterPivot)
		{
			CharacterPivot = CreateDefaultSubobject<USceneComponent>(TEXT("Character Pivot"));
			CharacterPivot->bEditableWhenInherited = true;
		}

		if(nullptr == HatPivot)
		{
			HatPivot = CreateDefaultSubobject<USceneComponent>(TEXT("Hat Pivot"));
			HatPivot->bEditableWhenInherited = true;
		}
	}
}

void APlayerPawn::SetupComponents()
{
	if(nullptr != GachaBallMeshComponent)
	{
		SetRootComponent(GachaBallMeshComponent);
		GachaBallMeshComponent->SetSimulatePhysics(true);
		GachaBallMeshComponent->SetHiddenInGame(true);
	}

	// Customisation
	{
		if(nullptr != GachaBallPivot)
		{
			GachaBallPivot->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepWorldTransform);
				
			if(nullptr != GachaBallChildComponent)
			{
				GachaBallChildComponent->AttachToComponent(GachaBallPivot, FAttachmentTransformRules::KeepWorldTransform);
			}
		}
		
		if(nullptr != CustomisationPivot)
		{
			CustomisationPivot->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepWorldTransform);
		
			if(nullptr != HatPivot)
			{
				HatPivot->AttachToComponent(CustomisationPivot, FAttachmentTransformRules::KeepWorldTransform);
				
				if(nullptr != HatChildComponent)
				{
					HatChildComponent->AttachToComponent(HatPivot, FAttachmentTransformRules::KeepWorldTransform);
				}
			}

			if(nullptr != CharacterPivot)
			{
				CharacterPivot->AttachToComponent(CustomisationPivot, FAttachmentTransformRules::KeepWorldTransform);
				
				if(nullptr != CharacterChildComponent)
				{
					CharacterChildComponent->AttachToComponent(CharacterPivot, FAttachmentTransformRules::KeepWorldTransform);
				}
			}
		}
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

			//D11.CP - Activate corresponding component to reflect gameplay effect
			switch (TestPickup->TypeEnum)
			{
			case EPowerupType::PWR_SHIELD: ActivateShieldPowerup(); break;
			case EPowerupType::PWR_2XSCORE:  if (TwoTimesScoreComponent) TwoTimesScoreComponent->SetPowerup(true); break;
			case EPowerupType::PWR_ADDSCORE: if (AddScoreComponent) AddScoreComponent->SetPowerup(true); break;
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

void APlayerPawn::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& Hit)
{
	if (nullptr == OtherActor || OtherActor == this)
	{
		return;
	}

	APlayerPawn* otherPlayer = Cast<APlayerPawn>(OtherActor);

	if(nullptr == otherPlayer)
	{
		return;
	}

	LastCollidedPlayerID = otherPlayer->PlayerID;
	
	OnPlayerCollide();
}

