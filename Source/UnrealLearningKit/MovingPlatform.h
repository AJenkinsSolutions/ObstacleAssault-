// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

UCLASS()
class UNREALLEARNINGKIT_API AMovingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingPlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	int32 MyInt = 99;

	UPROPERTY(EditAnywhere)
	int32 MyInt2 = 99;

	UPROPERTY(EditAnywhere)
	float MyFloat = 0.5; 

	UPROPERTY(EditAnywhere)
	bool MyBool = true;

		
	UPROPERTY(EditAnywhere)
	FVector MyVector = FVector(4370.0,12140.0,917.0);

	UPROPERTY(EditAnywhere)
	float Myx = 0; 
	

};
