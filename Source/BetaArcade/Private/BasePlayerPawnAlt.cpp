// Fill out your copyright notice in the Description page of Project Settings.


#include "BasePlayerPawnAlt.h"
#include "GameFramework/PlayerInput.h"


// Sets default values
ABasePlayerPawnAlt::ABasePlayerPawnAlt()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Create Static Mesh Component
	BallMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Ballmesh"));

	//Enable physics
	BallMesh->SetSimulatePhysics(true);

	//Set mesh as root component.
	SetRootComponent(BallMesh);

	// Create a spring-arm attached to the ball mesh.

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));

	SpringArm->bDoCollisionTest = false;
	SpringArm->SetUsingAbsoluteRotation(true);
	SpringArm->SetRelativeRotation(FRotator(-45.0f, 0.0f, 0.0f));
	SpringArm->TargetArmLength = 1000.0f;
	SpringArm->bEnableCameraLag = false;
	SpringArm->CameraLagSpeed = 5.0f;

	SpringArm->SetupAttachment(BallMesh);

	// Create a camera and attach to the spring-arm.

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));

	Camera->bUsePawnControlRotation = false;

	Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);

}

/**
Control the movement of the ball, called every frame.
*********************************************************************************/
void ABasePlayerPawnAlt::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector velocity = BallMesh->GetPhysicsLinearVelocity();
	float z = velocity.Z;

	velocity.Z = 0.0f;

	if (velocity.Size() > MaximumSpeed * 100.0f)
	{
		velocity.Normalize();
		velocity *= MaximumSpeed * 100.0f;
		velocity.Z = z;

		float brakingRatio = FMath::Pow(1.0f - FMath::Min(DashTimer, 1.0f), 2.0f);

		FVector mergedVelocity = FMath::Lerp(BallMesh->GetPhysicsLinearVelocity(), velocity, brakingRatio);

		BallMesh->SetPhysicsLinearVelocity(mergedVelocity);
	}
	else
	{
		BallMesh->AddForce(FVector(InputLongitude, InputLatitude, 0.0f) * ControllerForce * BallMesh->GetMass());
	}

	if (DashTimer > 0.0f)
	{
		DashTimer = FMath::Max(0.0f, DashTimer - DeltaTime);
	}

}

void ABasePlayerPawnAlt::Dash()
{
	// Only dash if we're not dashing already.

	if (DashTimer == 0.0f)
	{
		// Only dash if we have an existing velocity vector to dash towards.

		FVector velocity = BallMesh->GetPhysicsLinearVelocity();
		if (velocity.Size()> 1.0f)
		{
			velocity.Normalize();
			velocity *= DashForce * 1000.0f;

			// Add the impulse to the ball to perform the dash.

			BallMesh->AddImpulse(velocity);

			// Set the length of time that we're to dash for.

			DashTimer = 1.5f;
		}
	}
}


