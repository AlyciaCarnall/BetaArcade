// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/UserDefinedStruct.h"
#include "PlayerCustomisationInfo.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FPlayerCustomisationInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "IDs")
	int id_gatchball;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "IDs")
	int id_hat;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "IDs")
	int id_character;
};
