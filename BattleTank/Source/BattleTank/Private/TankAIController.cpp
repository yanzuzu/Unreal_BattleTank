// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "Tank.h"
#include "TankAIController.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAIController::Tick(float deltaTime)
{
	Super::Tick(deltaTime);
	auto playerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto controlTank = Cast<ATank>(GetPawn());
	if (playerTank == nullptr)
	{
		return;
	}
	controlTank->AimAt(playerTank->GetActorLocation());
	controlTank->Fire();
}

