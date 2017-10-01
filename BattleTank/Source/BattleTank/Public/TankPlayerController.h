// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PlayerController.h"
#include "Tank.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	ATank* GetTank() const;

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;
private:
	ATank* playerTank;
	void AimAtCrosshair();
	bool IsSightRayHit(FVector& outHitLocation) const;
	UPROPERTY(EditAnywhere)
	float CrosshairXlocation = 0.5;
	UPROPERTY(EditAnywhere)
	float CrosshairYlocation = 0.3333;
	UPROPERTY(EditAnywhere)
	float LineTraceRange = 1000000;

	bool GetLookDirection(FVector& outLookDirection) const;
	bool GetHitLocationByLookDir(FVector lookDirection, FVector& hitLocation) const;
};
