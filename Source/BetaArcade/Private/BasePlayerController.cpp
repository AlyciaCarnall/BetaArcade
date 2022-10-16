// Author : Craig Palmer v8009358.

#include "BasePlayerController.h"
#include "BasePlayerCharacter.h"

ABasePlayerController::ABasePlayerController() :
	possessedCharacter(nullptr)
{
}

void ABasePlayerController::BeginPlay()
{
	Super::BeginPlay();

	//TODO - Get possessed pawn and update member reference.
	possessedCharacter = Cast<ABasePlayerCharacter>(GetPawn());
}

void ABasePlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	//Setup gameplay input bindings

	//Movement
	InputComponent->BindAxis("MoveForward", this, &ABasePlayerController::CallMoveForward);
	InputComponent->BindAxis("MoveRight", this, &ABasePlayerController::CallMoveRight);
	//Actions
	InputComponent->BindAction("Bash", IE_Pressed, this, &ABasePlayerController::CallBash);
	InputComponent->BindAction("Shield", IE_Pressed, this, &ABasePlayerController::CallShield);
	InputComponent->BindAction("Shield", IE_Released, this, &ABasePlayerController::CallShield);
}

void ABasePlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bShieldActive)
	{
		fShieldTime += DeltaTime;
	}
}

void ABasePlayerController::CallMoveRight(float _value)
{
	// Commented out log to avoid cluttering output log. Allow testing of this Call Action	
	//UE_LOG(LogTemp, Warning, TEXT("MoveRight called from Player Controller with value (%f)."), _value);

	//Call action on character
	if (possessedCharacter)
	{
		possessedCharacter->HorizontalMovement(_value);
	}
}

void ABasePlayerController::CallMoveForward(float _value)
{
	// Commented out log to avoid cluttering output log. Allow testing of this Call Action	
	//UE_LOG(LogTemp, Warning, TEXT("MoveForward called from Player Controller with value (%f)."), _value);

	//Call action on character
	if (possessedCharacter)
	{
		possessedCharacter->VerticalMovement(_value);
	}

}

void ABasePlayerController::CallBash()
{
	UE_LOG(LogTemp, Warning, TEXT("Bash called from Player Controller"));

	//Call action on character
	if (possessedCharacter)
	{
		//possessPawn->CallBash();
	}
}

void ABasePlayerController::CallShield()
{
	//Craig - Kept track of shield held down time in case wanted to deplete time spent shielding in character, otherwise can do it here.

	bShieldActive = !bShieldActive;

	if (bShieldActive)
	{
		UE_LOG(LogTemp, Warning, TEXT("Shield called from Player Controller"));
		fShieldTime = 0;
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Shield Released"));

		if (possessedCharacter)
		{
			//possessedCharacter->Shield(fShieldTime);
		}
	}
}

