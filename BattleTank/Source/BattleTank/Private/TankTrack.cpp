// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankTrack.h"

void UTankTrack::SetThrottle(float throttle)
{
	//UE_LOG(LogTemp, Warning, TEXT("%s : throttle = %f"), *GetName(), throttle);

	FVector force = GetForwardVector() * throttle * MaxAvaliableForce;
	FVector location = GetComponentLocation();
	UPrimitiveComponent* primitiveObj = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	primitiveObj->AddForceAtLocation(force, location);
}


