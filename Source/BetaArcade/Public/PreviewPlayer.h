// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PreviewPlayer.generated.h"

UCLASS()
class BETAARCADE_API APreviewPlayer : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APreviewPlayer();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PreviewCharacter")
	int PlayerID { 0 };
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PreviewCharacter")
	UChildActorComponent* GachaBallChildComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PreviewCharacter")
	UChildActorComponent* HatChildComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PreviewCharacter")
	UChildActorComponent* CharacterChildComponent;

	
protected:
	void AddComponents();
	void SetupComponents();
};
