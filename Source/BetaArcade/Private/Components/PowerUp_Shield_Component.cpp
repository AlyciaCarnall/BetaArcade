// Author : Craig Palmer V8009358


#include "Components/PowerUp_Shield_Component.h"
#include "PlayerPawn.h"

UPowerUp_Shield_Component::UPowerUp_Shield_Component() : UBasePowerup_Component()
{
}

void UPowerUp_Shield_Component::SetPowerup(bool enable)
{
	//Base must come first for timers etc.
	Super::SetPowerup(enable);

	if (APlayerPawn const* const Player = Cast<APlayerPawn>(GetOwner()))
	{
		//Shield behavior - in progress
	}

	if (enable)
	{
		UE_LOG(LogClass, Log, TEXT("Shield On"));
	}
	else
	{
		UE_LOG(LogClass, Log, TEXT("Shield Off"));
	}
}
