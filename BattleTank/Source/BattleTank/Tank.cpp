// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "Tank.h"
#include "TankAmiingAt.h"
#include "TankBarrel.h"
#include "Projectile.h"
#include "TankMovementComponent.h"

// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	
	
}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

}

void ATank::AimAt(FVector location)
{
	tankAimingComponent->AimAt(location, LaunchSpeed);
}

void ATank::Fire()
{
	bool isReloaded = (FPlatformTime::Seconds() - LastReloadFireTime) > ReloadFireTime;
	if (barrel == nullptr || !isReloaded) return;
	LastReloadFireTime = FPlatformTime::Seconds();
	FVector startLocation = barrel->GetSocketLocation(FName("Projectile"));
	FRotator startRotator = barrel->GetSocketRotation(FName("Projectile"));
	AProjectile* projectile = GetWorld()->SpawnActor<AProjectile>(
		ProjectileBP,
		startLocation, 
		startRotator);
	projectile->Launch(LaunchSpeed);
}

