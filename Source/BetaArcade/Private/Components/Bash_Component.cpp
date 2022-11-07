// Author : Ryan Robson T7091365

#include "Bash_Component.h"

#include "PlayerPawn.h"

// Sets default values for this component's properties
UBash_Component::UBash_Component()
{
	PrimaryComponentTick.bCanEverTick = true;
}

// Called every frame
void UBash_Component::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if(CooldownCurrentTimeSeconds <= 0.0f)
	{
		return;
	}

	CooldownCurrentTimeSeconds -= DeltaTime;
}

void UBash_Component::TriggerBash()
{
	// Can't bash
	if(CooldownCurrentTimeSeconds > 0.0f)
	{
		return;
	}

	// Reset our cooldown
	CooldownCurrentTimeSeconds = CooldownMaxTimeSeconds;

	APlayerPawn const * const Player = Cast<APlayerPawn>(GetOwner());

	FVector const dashDir = FVector(Player->InputDir.X, Player->InputDir.Y, ZJumpHeight);
	Player->GachaBallMeshComponent->AddImpulse(dashDir * Speed, NAME_None, true);
}

