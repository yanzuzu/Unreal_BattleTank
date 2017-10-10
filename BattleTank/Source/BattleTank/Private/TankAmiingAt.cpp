// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAmiingAt.h"
#include "TankBarrel.h"

// Sets default values for this component's properties
UTankAmiingAt::UTankAmiingAt()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UTankAmiingAt::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UTankAmiingAt::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	// ...
}

void UTankAmiingAt::AimAt(FVector location, float launchSpeed )
{
	if (barrel == nullptr) { return; }

	FVector outLaunchVelocity;
	FVector startLocation = barrel->GetSocketLocation(FName("Projectile"));

	if (UGameplayStatics::SuggestProjectileVelocity(
		this,
		outLaunchVelocity,
		startLocation,
		location,
		launchSpeed,
		false,
		0,
		0,
		ESuggestProjVelocityTraceOption::DoNotTrace
	))
	{
		FVector aimArDirection = outLaunchVelocity.GetSafeNormal();
		MoveBarrelToward(aimArDirection);

		auto time = GetWorld()->GetTimeSeconds();
	}
}

void UTankAmiingAt::MoveBarrelToward(FVector aimAtDirection)
{
	auto barrelRotator = barrel->GetForwardVector().Rotation();
	auto aimRotator = aimAtDirection.Rotation();
	auto diffRotator = aimRotator - barrelRotator;
	barrel->Elevate(5);
}

void UTankAmiingAt::SetBarrel(UTankBarrel*  barrelMesh)
{
	barrel = barrelMesh;
}
