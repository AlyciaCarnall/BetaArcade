// Author : Ryan Robson T7091365
//Edit's by : Alycia Carnall

#include "BasePlayerCharacter.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ABasePlayerCharacter::ABasePlayerCharacter()
{
	// DO THESE FIRST
	AddCharacterComponents();
	SetupCharacterComponents();
	
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
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


// Called every frame
void ABasePlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//UE_LOG(LogTemp, Warning, TEXT("Velocity %s time %f"), *GetVelocity().ToString(), UGameplayStatics::GetRealTimeSeconds(GetWorld()));
}

// Called to bind functionality to input
void ABasePlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &ABasePlayerCharacter::VerticalMovement);
	PlayerInputComponent->BindAxis("MoveRight", this, &ABasePlayerCharacter::HorizontalMovement);
}


void ABasePlayerCharacter::VerticalMovement(float value)
{
	if(value == 0)
	{
		return;
	}
	AddMovementInput(GetActorForwardVector(), value);
}

void ABasePlayerCharacter::HorizontalMovement(float value)
{
	if(value == 0)
	{
		return;
	}

	AddMovementInput(GetActorRightVector(), value);
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

