// Author : Craig Palmer V8009358


#include "Components/BasePowerup_Component.h"
#include "PlayerPawn.h"

// Sets default values for this component's properties
UBasePowerup_Component::UBasePowerup_Component()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	ParentPlayer = Cast<APlayerPawn>(GetOwner());
}


bool UBasePowerup_Component::IsPowerupActive()
{
	return CooldownCurrentTimeSeconds > 0.0f;
}

void UBasePowerup_Component::SetPowerup(bool enable)
{
	CooldownCurrentTimeSeconds = enable ? CooldownMaxTimeSeconds : 0.0f;

	//Remaining behavior integrated in derived classes.
}

// Called every frame
void UBasePowerup_Component::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	//If active, reduce timer and reset when 0.
	if (IsPowerupActive())
	{
		//Countdown timer...
		CooldownCurrentTimeSeconds -= DeltaTime;

		//Is current time seconds > 0? If not disable powerup.
		if (!IsPowerupActive())
		{
			SetPowerup(false);
		}
	}
}

