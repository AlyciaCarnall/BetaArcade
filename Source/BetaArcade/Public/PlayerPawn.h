// Author : Ryan Robson T7091365
// Edit's by : Alycia Carnall, Craig Palmer

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PlayerPawn.generated.h"

UCLASS()
class BETAARCADE_API APlayerPawn : public APawn
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="BasePlayerPawn")
	UStaticMeshComponent* MeshComponent;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="BasePlayerPawn")
	class UBash_Component* BashComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BasePlayerPawn")
	class USphereComponent* PowerupCollectionSphere;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BasePlayerPawn")
	class UPowerUp_Shield_Component* PowerUpShieldComponent;

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

	virtual void Die();
	UFUNCTION(BlueprintCallable)
	virtual void FinishDying();

	void LimitMaximumSpeed() const;

	// RR - This should really be from a controller...
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual void Tick(float DeltaTime) override;

protected:
	void AddComponents();
	void SetupComponents();

	//CP - Collect in pickups in range of collection sphere
	UFUNCTION(BlueprintCallable, Category = "Pickups")
	void CollectPickups();
};
