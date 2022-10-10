// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "BetaArcadeGameModeBase.generated.h"

class ABasePlayerCharacter;

UCLASS()
class BETAARCADE_API ABetaArcadeGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public: 
	ABetaArcadeGameModeBase();

	//Time for each Match. 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameMode Settings")
	float MatchTime;
	//Should the Match timer go down at the current time?
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameMode Settings")
	bool IsTimerActive;

	//Reference to Player 1 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player References")
		ABasePlayerCharacter* player1;
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player References")
	//	ABasePlayerCharacter* player2;
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player References")
	//	ABasePlayerCharacter* player3;
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player References")
	//	ABasePlayerCharacter* player4;
	
};
