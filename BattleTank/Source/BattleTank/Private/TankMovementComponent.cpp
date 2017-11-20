// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankTrack.h"
#include "TankMovementComponent.h"


void UTankMovementComponent::Init(UTankTrack* leftTrackToSet, UTankTrack* rightTrackToSet)
{
	if (!leftTrackToSet || !rightTrackToSet)
	{
		UE_LOG(LogTemp, Warning, TEXT("left or right track is null"));
		return;
	}
	leftTrack = leftTrackToSet;
	rightTrack = rightTrackToSet;
}

void UTankMovementComponent::IntendMoveForward(float throwValue)
{
	leftTrack->SetThrottle(throwValue);
	rightTrack->SetThrottle(throwValue);
}

void UTankMovementComponent::IntendMoveTurn(float throwValue)
{
	leftTrack->SetThrottle(-throwValue);
	rightTrack->SetThrottle(throwValue);
}

void UTankMovementComponent::RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed)
{
	auto forwardV = GetOwner()->GetActorForwardVector().GetSafeNormal();
	auto moveV = MoveVelocity.GetSafeNormal();
	float throwValue = FVector::DotProduct(forwardV, moveV);
	FVector turnVectorValue = FVector::CrossProduct(forwardV, moveV);
	
	IntendMoveForward(throwValue);

	IntendMoveTurn(turnVectorValue.Z);
}

