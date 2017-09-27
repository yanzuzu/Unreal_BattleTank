// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAIController.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	ATank * tank = GetTank();
	if (tank == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("can't get the ai tank obj"));
		return;
	}

	UE_LOG(LogTemp, Warning, TEXT("the AI tank obj = %s"), *tank->GetName());
}

ATank* ATankAIController::GetTank() const
{
	return Cast<ATank>(GetPawn());
}
