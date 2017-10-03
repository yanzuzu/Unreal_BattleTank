// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "Tank.h"


// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
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

// Called every frame
void ATank::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

}

void ATank::AimAt(FVector location)
{
	tankAimingComponent->AimAt(location);
}

void ATank::SetBarrel(UStaticMeshComponent*  meshComponent)
{
	tankAimingComponent->SetBarrel(meshComponent);
}

