// Author : Ryan Robson T7091365


#include "Bash_Component.h"

// Sets default values for this component's properties
UBash_Component::UBash_Component()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UBash_Component::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UBash_Component::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

