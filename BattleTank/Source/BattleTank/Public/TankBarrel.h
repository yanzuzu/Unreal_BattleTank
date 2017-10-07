// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent), hidecategories = ("Collision"))
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	void Elevate(float degreePerSec);
	
	UPROPERTY(EditAnywhere, Category = "Setup")
	float MaxDegreePerSecond = 20;

	UPROPERTY(EditAnywhere, Category = "Setup")
	float MaxElevateDegree = 35;

	UPROPERTY(EditAnyWhere, Category = "Setup")
	float MinElevateDegree = 0;
};
