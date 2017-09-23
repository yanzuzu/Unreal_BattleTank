// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankPlayerController.h"
#include "Tank.h"

ATank* ATankPlayerController::GetTank() const
{
	return Cast<ATank>(GetPawn());
}



