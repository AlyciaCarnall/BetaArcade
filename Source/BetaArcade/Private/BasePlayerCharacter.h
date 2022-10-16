// Author : Ryan Robson T7091365

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Components/Bash_Component.h"
#include "BasePlayerCharacter.generated.h"

// R.Robson - We need to use the default player controller in the gamemode
// for this to work, will remove it at a later date anyways
//#define ENABLE_CHARACTER_INPUT

UCLASS()
class ABasePlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public: // Public Variables

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "BasePlayerCharacter")
	FText CharacterName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="BasePlayerCharacter")
	UBash_Component* BashComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="BasePlayerCharacter")
	float AccelerationTimeSeconds = 4.0f;

	// Sets default values for this character's properties
	ABasePlayerCharacter();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

//#ifdef ENABLE_CHARACTER_INPUT
	// Called to bind functionality to input
	//virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
//#endif

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void VerticalMovement(float value);

	void HorizontalMovement(float value);

	virtual void PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent) override;

	virtual void Die();

	UFUNCTION(BlueprintCallable)
	virtual void FinishDying();
	
protected: // Protected Variables
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BasePlayerCharacter")
	UCharacterMovementComponent* CharacterMovementRef;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void AddCharacterComponents();
	void SetupCharacterComponents();

	void UpdateMaxAcceleration();
	
	
};
