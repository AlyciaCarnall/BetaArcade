/*
Author : Craig Palmer V8009358
Shield Powerup 
Allows the player to decrease knock back for 10 seconds
*/


#include "Components/Shield_Component.h"
#include "PlayerPawn.h"

// Sets default values for this component's properties
UShield_Component::UShield_Component()
{
	PrimaryComponentTick.bCanEverTick = true;

	APlayerPawn const* const Player = Cast<APlayerPawn>(GetOwner());
	if (Player) LinearDampingCache = Player->MeshComponent->GetLinearDamping();
}

bool UShield_Component::IsShielded()
{
	return CooldownCurrentTimeSeconds > 0.0f;
}

void UShield_Component::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// If shielded, reduce timer and reset when 0 - Might be able to make this virtual tbf and use across all held powerups.
	if (IsShielded())
	{
		CooldownCurrentTimeSeconds -= DeltaTime;

		if (!IsShielded())
		{
			CooldownCurrentTimeSeconds = 0.0f;
			APlayerPawn const* const Player = Cast<APlayerPawn>(GetOwner());
			ToggleShield(false);
			// Shield Deactivate on Player.
			UE_LOG(LogClass, Log, TEXT("Shield DeActivated"));
		}
	}
}

void UShield_Component::TriggerShield()
{
	// Allow to be picked up, even if shield active to extend behavior.
	CooldownCurrentTimeSeconds = CooldownMaxTimeSeconds;
	ToggleShield(true);
	UE_LOG(LogClass, Log, TEXT("Shield Triggered"));
}

void UShield_Component::ToggleShield(bool enable)
{
	// TODO - Shield behavior. Either more resistant to forces or make metal depending on Design decision.

	if (APlayerPawn const* const Player = Cast<APlayerPawn>(GetOwner()))
	{
		Player->MeshComponent->SetLinearDamping(enable ? DampingAmount : LinearDampingCache );
	}
}


