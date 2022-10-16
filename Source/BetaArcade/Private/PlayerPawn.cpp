// Author : Ryan Robson T7091365
// Edit's by : Alycia Carnall, Craig Palmer

#include "PlayerPawn.h"

// Sets default values
APlayerPawn::APlayerPawn()
{
	// Setup our components first
	AddComponents();
	SetupComponents();

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
}

void APlayerPawn::SetupComponents()
{
	if(MeshComponent != nullptr)
	{
		SetRootComponent(MeshComponent);
		MeshComponent->SetSimulatePhysics(true);
		MeshComponent->SetHiddenInGame(false);
	}
}

// This should really be from a controller...
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

