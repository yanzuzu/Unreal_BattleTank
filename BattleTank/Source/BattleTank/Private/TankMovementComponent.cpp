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
	UE_LOG(LogTemp, Warning, TEXT("intend move forward, throw : %f"), throwValue);
	leftTrack->SetThrottle(throwValue);
	rightTrack->SetThrottle(throwValue);
}

