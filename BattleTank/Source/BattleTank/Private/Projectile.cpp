// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "Projectile.h"
#include "GameFramework/ProjectileMovementComponent.h"

// Sets default values
AProjectile::AProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	projectileCompoment = CreateDefaultSubobject<UProjectileMovementComponent>(FName("Projectile Movement Component"));
	if (projectileCompoment == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("can't construct the Projectile Movement component"));
		return;
	}
	projectileCompoment->bAutoActivate = false;
}

// Called when the game starts or when spawned
void AProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AProjectile::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

void AProjectile::Launch(float speed)
{
	if (projectileCompoment == nullptr) return;
	projectileCompoment->SetVelocityInLocalSpace(FVector::ForwardVector*speed);
	projectileCompoment->Activate();
}

