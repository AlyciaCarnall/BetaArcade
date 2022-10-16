// Author : Ryan Robson T7091365

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Components/Bash_Component.h"
#include "BasePlayerCharacter.generated.h"

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
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	void MoveForward(float value);
	void MoveRight(float value);
	void Bash();
	void Shield();

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
private:
	bool ShieldActive = false;
	float ShieldTimer = 0.0f;
	
};
