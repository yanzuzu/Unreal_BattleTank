// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class UTankBarrel;
class UTankAmiingAt;
class UTankTurret;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()
protected:
	UTankAmiingAt* tankAimingComponent = nullptr;
public:
	// Sets default values for this pawn's properties
	ATank();

	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetBarrel(UTankBarrel*  staticMeshComponent);

	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetTurret(UTankTurret*  turret);

	UFUNCTION(BlueprintCallable, Category = Setup)
	void Fire();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	void AimAt(FVector location);

	UPROPERTY(EditAnywhere, Category = Firing)
	float LaunchSpeed = 10000;
	
};
