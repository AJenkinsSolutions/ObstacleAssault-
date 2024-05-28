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

	UE_LOG(LogTemp, Display, TEXT("Configured move distancw %f"), MoveDistance);
	

	

}

// Called every framea
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	float OverShoot;

	//Get current location
	FVector CurrentLocation = GetActorLocation();

	// Adding a vector to out location vector
	CurrentLocation =  CurrentLocation + (PlatformVelocity * DeltaTime); 

	//Set location 
	SetActorLocation(CurrentLocation);
	
	//Send platform back
		//Check how far weve moved
	
	//distance from start
	float DistanceMoved = FVector::Dist(CurrentLocation, StartLocation);

	// Reverse direction
	if(DistanceMoved > MoveDistance)
	{
				
		//Reverse diection

		OverShoot = DistanceMoved - MoveDistance;


		UE_LOG(LogTemp, Display, TEXT("Overshoot %f"), OverShoot);

		FVector MoveDirection = PlatformVelocity.GetSafeNormal();

		StartLocation = StartLocation + MoveDirection * MoveDistance; 
		SetActorLocation(StartLocation);

		PlatformVelocity = PlatformVelocity * -1; 

	}
		

	
	

}




