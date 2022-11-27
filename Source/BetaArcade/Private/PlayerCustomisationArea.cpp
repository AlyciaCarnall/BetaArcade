// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCustomisationArea.h"

#include "Components/SceneCaptureComponent2D.h"

// Sets default values
APlayerCustomisationArea::APlayerCustomisationArea()
{
	// Setup our components first
	AddComponents();
	SetupComponents();
}

// Called when the game starts or when spawned
void APlayerCustomisationArea::BeginPlay()
{
	Super::BeginPlay();
	
}

void APlayerCustomisationArea::AddComponents()
{
	CaptureCameraComponent = CreateDefaultSubobject<USceneCaptureComponent2D>(TEXT("Capture Camera"));
}

void APlayerCustomisationArea::SetupComponents()
{
	SetRootComponent(CreateDefaultSubobject<USceneComponent>(TEXT("Root")));
	
	if(nullptr != CaptureCameraComponent)
	{
		CaptureCameraComponent->SetupAttachment(RootComponent);
	}
}