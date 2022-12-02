// Fill out your copyright notice in the Description page of Project Settings.


#include "PreviewPlayer.h"

#include "BaseGameInstance.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
APreviewPlayer::APreviewPlayer()
{
	// Setup our components first
	AddComponents();
	SetupComponents();
}

void APreviewPlayer::RebuildCustomisation()
{
	UBaseGameInstance const * const GI = Cast<UBaseGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));
	
	if(nullptr != GachaBallChildComponent)
	{
		if(nullptr != GI)
		{
			GachaBallChildComponent->SetChildActorClass(GI->GetPlayerGachaBallActor(PlayerID));
		}
	}
	
	if(nullptr != HatChildComponent)
	{
		if(nullptr != GI)
		{
			HatChildComponent->SetChildActorClass(GI->GetPlayerHatActor(PlayerID));
		}
	}
	
	if(nullptr != CharacterChildComponent)
	{
		if(nullptr != GI)
		{
			CharacterChildComponent->SetChildActorClass(GI->GetPlayerCharacterActor(PlayerID));
		}
	}
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

void APreviewPlayer::BeginPlay()
{
	Super::BeginPlay();
	RebuildCustomisation();
}
