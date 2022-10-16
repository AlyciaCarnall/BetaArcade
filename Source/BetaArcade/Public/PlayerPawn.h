// Author : Ryan Robson T7091365
// Edit's by : Alycia Carnall, Craig Palmer

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Components/Bash_Component.h"
#include "PlayerPawn.generated.h"

UCLASS()
class BETAARCADE_API APlayerPawn : public APawn
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="BasePlayerPawn")
	UStaticMeshComponent* MeshComponent;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="BasePlayerPawn")
	UBash_Component* BashComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="BasePlayerPawn")
	float RollSpeed = 15.0f;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="BasePlayerPawn")
	float MaximumRollSpeed = 20.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="BasePlayerPawn")
	FVector2D InputDir = FVector2D::ZeroVector;
	
	// Sets default values for this pawn's properties
	APlayerPawn();

	void MoveForward(float value);
	void MoveRight(float value);
	
	UFUNCTION(BlueprintCallable)
	void Bash();
	UFUNCTION(BlueprintCallable)
	void Shield();

	virtual void Die();
	UFUNCTION(BlueprintCallable)
	virtual void FinishDying();

	void LimitMaximumSpeed() const;

	// This should really be from a controller...
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
protected:
	bool ShieldActive = false;
	float ShieldTimer = 0.0f;
	
	void AddComponents();
	void SetupComponents();
};
