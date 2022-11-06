// Fill out your copyright notice in the Description page of Project Settings.


#include "PreviewPlayer.h"

// Sets default values
APreviewPlayer::APreviewPlayer()
{
	// Setup our components first
	AddComponents();
	SetupComponents();
}

void APreviewPlayer::AddComponents()
{
	GachaBallChildComponent = CreateDefaultSubobject<UChildActorComponent>(TEXT("Gacha Ball Mesh"));
	HatChildComponent = CreateDefaultSubobject<UChildActorComponent>(TEXT("Hat Mesh"));
	CharacterChildComponent = CreateDefaultSubobject<UChildActorComponent>(TEXT("Character Mesh"));
}

void APreviewPlayer::SetupComponents()
{
	SetRootComponent(CreateDefaultSubobject<USceneComponent>(TEXT("Root")));

	if(nullptr != GachaBallChildComponent)
	{
		GachaBallChildComponent->SetupAttachment(RootComponent);
		GachaBallChildComponent->SetComponentTickEnabled(false);
	}
	
	if(nullptr != HatChildComponent)
	{
		HatChildComponent->SetupAttachment(RootComponent);
		HatChildComponent->SetComponentTickEnabled(false);
	}
	
	if(nullptr != CharacterChildComponent)
	{
		CharacterChildComponent->SetupAttachment(RootComponent);
		CharacterChildComponent->SetComponentTickEnabled(false);
	}
}
