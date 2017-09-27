// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankPlayerController.h"
#include "Tank.h"


void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	ATank* tank = GetTank();
	if (tank == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("can't get the tank"));
		return;
	}
	UE_LOG(LogTemp, Warning, TEXT("TankPlayerController Tank !!!= %s"),*tank->GetName());
}

ATank* ATankPlayerController::GetTank() const
{
	return Cast<ATank>(GetPawn());
}



