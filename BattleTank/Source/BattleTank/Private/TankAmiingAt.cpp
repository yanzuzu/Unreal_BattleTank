// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAmiingAt.h"


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

void UTankAmiingAt::AimAt(FVector location)
{
	auto barrelLocation = *barrel->GetComponentLocation().ToString();
	UE_LOG(LogTemp, Warning, TEXT("%s aim at location: %s from: %s"), *GetOwner()->GetName(), *location.ToString(), barrelLocation);
}

void UTankAmiingAt::SetBarrel(UStaticMeshComponent*  meshComponent)
{
	barrel = meshComponent;
}
