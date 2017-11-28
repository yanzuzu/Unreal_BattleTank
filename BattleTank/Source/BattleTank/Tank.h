// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class UTankBarrel;
class UTankAmiingAt;
class UTankTurret;
class AProjectile;
class UTankTrack;
class UTankMovementComponent;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()
protected:
	UPROPERTY(BlueprintReadOnly)
	UTankAmiingAt* tankAimingComponent = nullptr;

public:
	// Sets default values for this pawn's properties
	ATank();

	UFUNCTION(BlueprintCallable, Category = "Setup")
	void Fire();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	void AimAt(FVector location);

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float LaunchSpeed = 10000;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	TSubclassOf<AProjectile> ProjectileBP;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float ReloadFireTime = 3;

	double LastReloadFireTime = 0;

	UTankBarrel* barrel = nullptr;

};
