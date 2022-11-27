// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "PlayerCustomisationInfo.h"
#include "PlayerID.h"
#include "BaseGameInstance.generated.h"

UENUM(BlueprintType)
enum class EGameModeType : uint8
{
	E_Brawl				UMETA(DisplayName = "BRAWL"), //Customize no of lives and timelimit.
	E_TeamBattle		UMETA(DisplayName = "TEAMBATTLE"), // 
	E_KingOfTheHill		UMETA(DisplayName = "KING OF THE HILL"), // Points over time in designated location , no death limit
	E_CrownSnatch		UMETA(DisplayName = "CROWN SNATCH"), //Capture the Flag, no death limit
	E_RoyalRumble		UMETA(DisplayName = "ROYAL RUMBLE") //Tournament Style - Tournament of 4 players, winner proceeds 
};


UCLASS()
class BETAARCADE_API UBaseGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	//The GameModes current type - TODO - Will need to reset upon Main Menu
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameMode References")
		EGameModeType GameModeType;

	//Time for each Match. 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameMode Settings")
		float MatchTime;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "GameMode Customisation")
	TArray<TSubclassOf<AActor>> CustomisationGachaBalls;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "GameMode Customisation")
	TArray<TSubclassOf<AActor>> CustomisationHats;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "GameMode Customisation")
	TArray<TSubclassOf<AActor>> CustomisationCharacters;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "GameMode Customisation")
	TArray<FPlayerCustomisationInfo> CustomisationPlayerInfo;

	TSubclassOf<AActor> const GetPlayerGachaBallActor(EPlayerID const PlayerID) const;
	TSubclassOf<AActor> const GetPlayerHatActor(EPlayerID const PlayerID) const;
	TSubclassOf<AActor> const GetPlayerCharacterActor(EPlayerID const PlayerID) const;
};
