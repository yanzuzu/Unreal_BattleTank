// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	// set throttle between -1 to 1
	UFUNCTION(BlueprintCallable, Category = Input)
	void SetThrottle(float throttle);

	UPROPERTY(EditDefaultsOnly, Category = Setup)
	float MaxAvaliableForce = 400000;
};
