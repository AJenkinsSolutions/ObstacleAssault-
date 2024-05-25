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

	SetActorLocation(InitLocation);
	

}

// Called every framea
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


	FVector CurrentLocation = GetActorLocation();

	CurrentLocation =  CurrentLocation + PlatformVelocity * DeltaTime; 

	SetActorLocation(CurrentLocation);

	
}


// void AMovingPlatform:: MoveFwd(){

// 	MyVector.X = MyVector.X + 1; 
// }

// void AMovingPlatform:: MoveBkwd(){

// 	MyVector.X = MyVector.X - 1; 
// }

// void AMovingPlatform:: MoveLt(){

// 	MyVector.Y = MyVector.Y - 1; 
// }

// void AMovingPlatform:: MoveRt(){

// 	MyVector.Y = MyVector.Y + 1; 
// }
	



