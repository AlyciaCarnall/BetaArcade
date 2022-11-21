// Author : Ryan Robson T7091365
// Edit's by : Alycia Carnall, Craig Palmer

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PlayerPawn.generated.h"

UCLASS(ClassGroup = (Custom), BlueprintType, Blueprintable, meta = (BlueprintSpawnableComponent))
class BETAARCADE_API APlayerPawn : public APawn
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="BasePlayerPawn")
	UStaticMeshComponent* GachaBallMeshComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="BasePlayerPawn")
	UStaticMeshComponent* HatMeshComponent;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="BasePlayerPawn")
	UStaticMeshComponent* CharacterMeshComponent;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="BasePlayerPawn")
	class UBash_Component* BashComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Powerups")
	class UShield_Powerup_Component* ShieldComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Powerups")
	class UBasePowerup_Component* TwoTimesScoreComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BasePlayerPawn")
	class USphereComponent* PowerupCollectionSphere;

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

	UFUNCTION(BlueprintCallable, Category = "Pickups")
	void ActivatePowerup();

	virtual void Die();
	UFUNCTION(BlueprintCallable)
	virtual void FinishDying();

	UFUNCTION(BlueprintCallable)
	void LimitMaximumSpeed() const;
	
	UFUNCTION(BlueprintCallable)
	void OrientCharacter();

	UFUNCTION(BlueprintCallable)
	void RebuildCustomisation();
	
	// This should really be from a controller...
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintImplementableEvent)
	void OnBash();

protected:
	void AddComponents();
	void SetupComponents();

	//CP - Collect in pickups in range of collection sphere
	UFUNCTION(BlueprintCallable, Category = "Pickups")
	void CollectPickups();
};
