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

	playerTank = GetPlayerTank();
	if (playerTank == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("can't get the player tank obj~~"));
		return;
	}

}

void ATankAIController::Tick(float deltaTime)
{
	Super::Tick(deltaTime);
	if (playerTank == nullptr)
	{
		return;
	}
	GetTank()->AimAt(playerTank->GetActorLocation());
}

ATank* ATankAIController::GetTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}
