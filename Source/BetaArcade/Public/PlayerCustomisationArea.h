// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PreviewPlayer.h"
#include "GameFramework/Actor.h"
#include "PlayerCustomisationArea.generated.h"

UCLASS()
class BETAARCADE_API APlayerCustomisationArea : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APlayerCustomisationArea();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PreviewCharacter")
	TEnumAsByte<EPlayerID> PlayerID;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CustomisationArea")
	USceneCaptureComponent2D* CaptureCameraComponent;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CustomisationArea")
	APreviewPlayer* PreviewPlayerComponent;

	UFUNCTION(BlueprintCallable)
	void UpdatePreviewPlayerID();
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void AddComponents();
	void SetupComponents();
};
