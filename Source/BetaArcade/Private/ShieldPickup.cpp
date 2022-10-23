// Author : Craig Palmer V8009358


#include "ShieldPickup.h"

// Sets default values for this actor's properties
AShieldPickup::AShieldPickup()
{
	GetMesh()->SetSimulatePhysics(true);

}

void AShieldPickup::WasCollected_Implementation()
{
	Super::WasCollected_Implementation();

	//Destroy the pickup - May just be able to hide and reenable for pickups rather than destroy.
	Destroy();
}
