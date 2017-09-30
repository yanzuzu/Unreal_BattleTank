// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankPlayerController.h"
#include "Tank.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	playerTank = GetTank();
	if (playerTank == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("can't get the tank"));
		return;
	}
	UE_LOG(LogTemp, Warning, TEXT("TankPlayerController Tank !!!= %s"),*playerTank->GetName());
}

void ATankPlayerController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	AimAtCrosshair();
}

ATank* ATankPlayerController::GetTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimAtCrosshair()
{
	if (playerTank == nullptr)
	{
		return;
	}
	FVector hitLocation;
	if (IsSightRayHit(hitLocation))
	{
		//UE_LOG(LogTemp, Warning, TEXT("hitLocation : %s"), *hitLocation.ToString());

	}
}

bool ATankPlayerController::IsSightRayHit(FVector& outHitLocation) const
{
	int32 viewPortSizeX, viewPortSizeY;
	GetViewportSize(viewPortSizeX, viewPortSizeY);
	FVector2D screenPos = FVector2D(viewPortSizeX*CrosshairXlocation, viewPortSizeY*CrosshairYlocation);
	UE_LOG(LogTemp, Warning, TEXT("screenPos = %s"), *screenPos.ToString());

	return true;
}



