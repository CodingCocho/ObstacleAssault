// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

UCLASS()
class OBSTACLEASSAULT_API AMovingPlatform : public AActor
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

private: 

	// Hold the velocity vector
	UPROPERTY(EditAnywhere)
	FVector velocity = FVector(0, 100, 0);

	// Hold the travel distance limit
	UPROPERTY(EditAnywhere)
	float maxDistance = 100;

	// Hold the distance between the platform and it's starting location
	UPROPERTY(VisibleAnywhere)
	float distanceMoved;
	
	// Hold the overshot distance between the platform and it's ending location
	UPROPERTY(VisibleAnywhere)
	float distanceOvershot;
	
	// Hold the starting location
	FVector startingLocation;

	/*
	Moves the platform using deltatime up to a certain amount then it reverses
	the movement.
	@param float deltaTime the rate of movement using the user's FPS
	@return void
	*/
	void movePlatform(float deltaTime);

	// Hold the rotation amount
	UPROPERTY(EditAnywhere)
	FRotator angularVelocity = FRotator(0, 0, 0);

	/*
	Rotate the platform using deltatime 
	@param float deltaTime the rate of movement using the user's FPS
	@return void
	*/
	void rotatePlatform(float deltaTime);
};
