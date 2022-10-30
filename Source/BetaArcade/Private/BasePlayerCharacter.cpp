// Author : Ryan Robson T7091365
//Edit's by : Alycia Carnall, Craig Palmer

#include "BasePlayerCharacter.h"
#include "Components/CapsuleComponent.h"
#include "Components/SphereComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Powerup.h"



// Sets default values
ABasePlayerCharacter::ABasePlayerCharacter()
{
	// DO THESE FIRST
	AddCharacterComponents();
	SetupCharacterComponents();
	PrimaryActorTick.bCanEverTick = true;

	GetCapsuleComponent()->SetCollisionResponseToChannel(ECollisionChannel::ECC_Camera, ECollisionResponse::ECR_Ignore);
	GetMesh()->VisibilityBasedAnimTickOption = EVisibilityBasedAnimTickOption::AlwaysTickPoseAndRefreshBones;
	GetMesh()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	GetMesh()->SetCollisionProfileName(FName("NoCollision"));

#ifdef ENABLE_CHARACTER_INPUT
	AutoPossessPlayer = EAutoReceiveInput::Player0;
#endif
}

// Called when the game starts or when spawned
void ABasePlayerCharacter::BeginPlay()
{
	Super::BeginPlay();

	UpdateMaxAcceleration();
	
}

void ABasePlayerCharacter::AddCharacterComponents()
{
	// Storing this because it's stupid to continually call a getter function when the variable should be protected...
	CharacterMovementRef = GetCharacterMovement();
	BashComponent = CreateDefaultSubobject<UBash_Component>(TEXT("Character Bash"));

	//Setting up the collection sphere for pickups.
	CollectionSphere = CreateDefaultSubobject<USphereComponent>(TEXT("Powerup Collection Sphere"));
	CollectionSphere->SetupAttachment(RootComponent);
	CollectionSphere->SetSphereRadius(200.0f);
}

void ABasePlayerCharacter::SetupCharacterComponents()
{
	RootComponent->SetHiddenInGame(false);
	
	UpdateMaxAcceleration();

}


void ABasePlayerCharacter::UpdateMaxAcceleration()
{
	CharacterMovementRef->MaxAcceleration = (CharacterMovementRef->MaxWalkSpeed / AccelerationTimeSeconds);
	//UE_LOG(LogTemp, Warning, TEXT("MaxWalkSpeed %f acceleration_time_seconds %f MaxAcceleration %f"), character_movement->MaxWalkSpeed, acceleration_time_seconds, character_movement->MaxAcceleration);
}


void ABasePlayerCharacter::CollectPickups()
{
	TArray<AActor*> CollectedActors;
	CollectionSphere->GetOverlappingActors(CollectedActors);
	for (AActor* Actor : CollectedActors)
	{
		APowerup* const TestPickup = Cast<APowerup>(Actor);
		if (TestPickup && !TestPickup->IsPendingKill() && TestPickup->IsActive())
		{
			TestPickup->WasCollected();
			TestPickup->SetActive(false);
		}
	}
}

// Called every frame
void ABasePlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//Recrd how long shield active.
	if (ShieldActive)
	{
		ShieldTimer += DeltaTime;
	}

	//UE_LOG(LogTemp, Warning, TEXT("Velocity %s time %f"), *GetVelocity().ToString(), UGameplayStatics::GetRealTimeSeconds(GetWorld()));

	CollectPickups();
}

// Called to bind functionality to input
void ABasePlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &ABasePlayerCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ABasePlayerCharacter::MoveRight);

	//Actions
	PlayerInputComponent->BindAction("Bash", IE_Pressed, this, &ABasePlayerCharacter::Bash);
	PlayerInputComponent->BindAction("Shield", IE_Pressed, this, &ABasePlayerCharacter::Shield);
	PlayerInputComponent->BindAction("Shield", IE_Released, this, &ABasePlayerCharacter::Shield);
}


void ABasePlayerCharacter::MoveForward(float value)
{
	if(value == 0) return;
	UE_LOG(LogTemp, Warning, TEXT("MoveForward called from Player Controller with value (%f)."), value);
	AddMovementInput(GetActorForwardVector(), value);
}

void ABasePlayerCharacter::MoveRight(float value)
{
	if (value == 0) return;
	UE_LOG(LogTemp, Warning, TEXT("MoveRight called from Player Controller with value (%f)."), value);
	AddMovementInput(GetActorRightVector(), value);
}

void ABasePlayerCharacter::Bash()
{
	//Call Bash Component . TODO
}

void ABasePlayerCharacter::Shield()
{
	//Craig - Kept track of shield held down time in case wanted to deplete time spent shielding in character, otherwise can do it here.
	//Also we can probably move to a dedicated component.
	ShieldActive = !ShieldActive;

	if (ShieldActive)
	{
		UE_LOG(LogTemp, Warning, TEXT("Shield called from Player Controller"));
		ShieldTimer = 0.0f;
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Shield Released"));
	}
}

void ABasePlayerCharacter::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);

	UpdateMaxAcceleration();
}

void ABasePlayerCharacter::Die()
{
	GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	GetCharacterMovement()->GravityScale = 0;
	GetCharacterMovement()->Velocity = FVector(0);

	FinishDying();
}

void ABasePlayerCharacter::FinishDying()
{
	Destroy();
}

