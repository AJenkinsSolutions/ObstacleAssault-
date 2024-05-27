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
	

}

// Called every framea
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//Get current location
	FVector CurrentLocation = GetActorLocation();

	// Adding a vector to out location vector
	CurrentLocation =  CurrentLocation + PlatformVelocity * DeltaTime; 

	//Set location 
	SetActorLocation(CurrentLocation);
	
	//Send platform back
		//Check how far weve moved
		// Init location - current location - the delta is the distance
	FVector diff = CurrentLocation - StartLocation; 

	 dist = FVector::Dist(CurrentLocation, StartLocation);
		
		// Reverse direction
	

}




