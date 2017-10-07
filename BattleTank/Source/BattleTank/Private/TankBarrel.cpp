// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankBarrel.h"


void UTankBarrel::Elevate(float degreePerSec)
{
	UE_LOG(LogTemp, Warning, TEXT("barrel elevate degree: %f"), degreePerSec);
}

