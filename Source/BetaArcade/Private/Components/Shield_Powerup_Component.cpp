// Fill out your copyright notice in the Description page of Project Settings.

#include "Components/Shield_Powerup_Component.h"
#include "Components/SphereComponent.h"
#include "PlayerPawn.h"

UShield_Powerup_Component::UShield_Powerup_Component() : UBasePowerup_Component()
{
	//Setting up the collection sphere for pickups.
}

void UShield_Powerup_Component::SetPowerup(bool enable)
{
	Super::SetPowerup(enable);

	APlayerPawn const* const Player = Cast<APlayerPawn>(GetOwner());

	//if (Player)
	//{
	//	if (enable)
	//	{
	//		UE_LOG(LogClass, Log, TEXT("Shield Enabled"));
	//		Player->ShieldSphere->Activate(false);
	//	}

	//	else
	//	{
	//		UE_LOG(LogClass, Log, TEXT("Shield Disabled"));
	//		Player->ShieldSphere->Deactivate();
	//	}
	//}

}
