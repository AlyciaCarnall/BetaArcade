// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseGameInstance.h"



TSubclassOf<AActor> const UBaseGameInstance::GetPlayerGachaBallActor(EPlayerID const PlayerID) const
{
	int const offsetPlayerID = static_cast<int>(PlayerID) - 1;
	if(offsetPlayerID < 0 || offsetPlayerID >= CustomisationPlayerInfo.Num())
	{
		return AActor::StaticClass();
	}

	int gachaBallID = CustomisationPlayerInfo[offsetPlayerID].id_gatchball;

	if(gachaBallID >= CustomisationGachaBalls.Num())
	{
		return AActor::StaticClass();
	}
	
	return CustomisationGachaBalls[gachaBallID];
}

TSubclassOf<AActor> const UBaseGameInstance::GetPlayerHatActor(EPlayerID const PlayerID) const
{
	int const offsetPlayerID = static_cast<int>(PlayerID) - 1;
	
	if(offsetPlayerID < 0 || offsetPlayerID >= CustomisationPlayerInfo.Num())
	{
		return AActor::StaticClass();
	}

	int hatID = CustomisationPlayerInfo[offsetPlayerID].id_hat;

	if(hatID >= CustomisationHats.Num())
	{
		return AActor::StaticClass();
	}
	
	return CustomisationHats[hatID];
}

TSubclassOf<AActor> const UBaseGameInstance::GetPlayerCharacterActor(EPlayerID const PlayerID) const
{
	int const offsetPlayerID = static_cast<int>(PlayerID) - 1;
	
	if(offsetPlayerID < 0 || offsetPlayerID >= CustomisationPlayerInfo.Num())
	{
		return AActor::StaticClass();
	}

	int characterID = CustomisationPlayerInfo[offsetPlayerID].id_character;

	if(characterID >= CustomisationCharacters.Num())
	{
		return AActor::StaticClass();
	}
	
	return CustomisationCharacters[characterID];
}
