// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "TankAmiingAt.generated.h"

UENUM()
enum class EFiringStatus :uint8
{
	Reloading,
	Aiming,
	Locked
};

class UTankBarrel;
class UTankTurret;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAmiingAt : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAmiingAt();

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

	void AimAt(FVector location , float launchSpeed );
	
	void SetBarrel(UTankBarrel*  barrel);
	void SetTurret(UTankTurret*  turret);
protected:
	UPROPERTY(BlueprintReadOnly, Category = Setups)
	EFiringStatus firingStatus = EFiringStatus::Reloading;
private:
	UTankBarrel* barrel = nullptr;
	UTankTurret* turret = nullptr;
	void MoveBarrelToward(FVector aimAtDirection);
	void MoveTurretToward(FVector aimAtDirection);
	
};
