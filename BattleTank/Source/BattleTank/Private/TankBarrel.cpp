// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankBarrel.h"


void UTankBarrel::Elevate(float relativeSpeed)
{
	relativeSpeed = FMath::Clamp<float>(relativeSpeed, -1, 1);
	auto changeElevation = relativeSpeed * MaxDegreePerSecond * GetWorld()->DeltaTimeSeconds;
	auto finalElevation = RelativeRotation.Pitch + changeElevation;
	finalElevation = FMath::Clamp<float>(finalElevation, MinElevateDegree, MaxElevateDegree);
	SetRelativeRotation(FRotator(finalElevation,0,0));
}

