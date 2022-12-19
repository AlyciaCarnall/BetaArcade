// Author : Craig Palmer V8009358

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Powerup.generated.h"

UENUM(BlueprintType)
enum class EPowerupType : uint8
{
	PWR_NONE	UMETA(DisplayName = "None"),
	PWR_SHIELD	UMETA(DisplayName = "Shield"),
	PWR_2XSCORE	UMETA(DisplayName = "Double Points"),
	PWR_ADDSCORE UMETA(DisplayName = "Add Points"),
	PWR_NUM UMETA(DisplayName = "Enum Total")
};

UCLASS()
class BETAARCADE_API APowerup : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APowerup();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//Return the mesh for the pickup
	FORCEINLINE class UStaticMeshComponent* GetMesh() const { return PickupMesh; }

	//Return whether or not the pickup is active
	UFUNCTION(BlueprintPure, Category = "Pickup")
	bool IsActive();
	
	//Allows other classes to safely change whether pickup is active.
	UFUNCTION(BlueprintCallable, Category = "Pickup")
	void SetActive(bool NewPickupState);

	//To call when pickup is collected by player
	UFUNCTION(BlueprintNativeEvent, Category = "Pickup")
	void WasCollected();
	virtual void WasCollected_Implementation();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EPowerupType TypeEnum;

protected:

	//True when the pickup can be used, and false when pickup is deactivated
	bool bIsActive;

private:
	//Static mesh to represent the pickup in the level.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Pickup", meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent* PickupMesh;

};
