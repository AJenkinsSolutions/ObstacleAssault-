// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	StartLocation = GetActorLocation();	

	//Logging
	//Fstring
	//Inteliense Short cut - 'ulog'
	UE_LOG(LogTemp, Display, TEXT("Text Message log Here"));

}

// Called every framea
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	MovePlatform(DeltaTime);

	

}
// Specify which class 
//:: == scope resolution operator
void AMovingPlatform::MovePlatform(float DeltaTime)
{

	

	// Reverse direction
	if(ShouldPlatformReturn())
	{
			
		FVector MoveDirection = PlatformVelocity.GetSafeNormal();
		StartLocation = StartLocation + MoveDirection * MoveDistance; 
		SetActorLocation(StartLocation);
		PlatformVelocity = PlatformVelocity * -1; 

	}
	else
	{
		// Move Platform Forward
		FVector CurrentLocation =  GetActorLocation();
		CurrentLocation =  CurrentLocation + (PlatformVelocity * DeltaTime); 
		SetActorLocation(CurrentLocation);
		
	}

}


void AMovingPlatform::RotatePlatform(float DeltaTime)
{
	UE_LOG(LogTemp, Display, TEXT("Rotating....%s "), *GetName());
	
	//Impl...
}

bool AMovingPlatform::ShouldPlatformReturn() const
{	
	
	float DistanceMoved = GetDistanceMoved();

	return DistanceMoved > MoveDistance;
}

float AMovingPlatform::GetDistanceMoved() const
{
	//Distanvr Moved
	return FVector::Dist(StartLocation, GetActorLocation());
}