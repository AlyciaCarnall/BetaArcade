// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "BasePlayerPawnAlt.generated.h"

UCLASS()
class ABasePlayerPawnAlt : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABasePlayerPawnAlt();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = BallBearing)
		UStaticMeshComponent* BallMesh;

	// Spring arm for positioning the camera above the ball(DEBUG)
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = BallBearing)
		USpringArmComponent* SpringArm = nullptr;

	// Camera to view the ball(DEBUG)
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = BallBearing)
		UCameraComponent* Camera = nullptr;

	// How much force to use to push the ball around.
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = BallBearing)
		float ControllerForce = 250.0f;

	// How much force to use to push the ball into the air.
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = BallBearing)
		float JumpForce = 50.0f;

	// How much force to use to have the ball bearing dash.
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = BallBearing)
		float DashForce = 150.0f;

	// The maximum speed in meters per second.
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = BallBearing)
		float MaximumSpeed = 4.0f;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Move the ball bearing with the given force longitudinally on the X axis.
	void MoveLongitudinally(float value)
	{
		InputLongitude = value;
	}

	// Move the ball bearing with the given force longitudinally on the Y axis.
	void MoveLaterally(float value)
	{
		InputLatitude = value;
	}

	// Have the ball perform a dash.
	void Dash();

private:

	// The current longitude input received from the player.
	float InputLongitude = 0.0f;

	// The current latitude input received from the player.
	float InputLatitude = 0.0f;

	// Timer used to control the dashing of the ball bearing.
	float DashTimer = 0.0f;

};
