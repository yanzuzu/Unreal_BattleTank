// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "Tank.h"
#include "TankAmiingAt.h"

// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	tankAimingComponent = CreateDefaultSubobject<UTankAmiingAt>(FName("Aiming Component"));
	if (tankAimingComponent == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("can't construct the aiming component"));
	}
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

void ATank::SetBarrel(UTankBarrel*  meshComponent)
{
	tankAimingComponent->SetBarrel(meshComponent);
}

void ATank::SetTurret(UTankTurret*  turret)
{
	tankAimingComponent->SetTurret(turret);
}

void ATank::Fire()
{
	auto time = GetWorld()->TimeSeconds;
	UE_LOG(LogTemp, Warning, TEXT("time = %f fire!!"),time);
}

