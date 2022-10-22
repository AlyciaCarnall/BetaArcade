// Author : Craig Palmer V8009358

#pragma once

#include "CoreMinimal.h"
#include "Pickup.h"
#include "ShieldPickup.generated.h"

/**
 * 
 */
UCLASS()
class BETAARCADE_API AShieldPickup : public APickup
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AShieldPickup();

	//Override the WasCollected function - Use Implementation because its a Blueprint Native Event
	void WasCollected_Implementation() override;
	
};
