// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankTurret.h"



void UTankTurret::Rotate(float relativeSpeed)
{
	relativeSpeed = FMath::Clamp<float>(relativeSpeed, -1, 1);
	auto changeDegree = relativeSpeed * MaxRotateDegree * GetWorld()->DeltaTimeSeconds;
	auto finalRsult = RelativeRotation.Yaw + changeDegree;
	SetRelativeRotation(FRotator(0, finalRsult, 0));
}

