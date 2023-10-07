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

	// Hold the starting location of the actor
	startingLocation = GetActorLocation();
}


// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	movePlatform(DeltaTime);
	rotatePlatform(DeltaTime);
}

/*
Moves the platform using deltatime up to a certain amount then it reverses
the movement.
@param float deltaTime the rate of movement using the user's FPS
@return void
*/
void AMovingPlatform::movePlatform(float deltaTime)
{

	// Hold the actor's current location
	FVector currentLocation  = GetActorLocation();

	// Add the velocity using the FPS
	currentLocation += velocity * deltaTime;

	// Hold the distance difference from the starting location
	distanceMoved = FVector::Dist(startingLocation, currentLocation);

	// Set the location for the actor
	SetActorLocation(currentLocation);

	// Check if the actor moved past the max distance
	if(distanceMoved > maxDistance)
	{
		// Hold the name
		FString name = GetName();

		// Hold the overshot distance
		distanceOvershot = distanceMoved - maxDistance;

		// Print the overshot distance 
		UE_LOG(LogTemp, Display, TEXT("Actor: %s overshot by %f"), *name, distanceOvershot);

		// Hold the normal vector of the move direction
		FVector moveDirection = velocity.GetSafeNormal();

		// Hold the new starting location using the normal vector
		startingLocation += moveDirection * distanceMoved;
		
		// Set the new location 
		SetActorLocation(startingLocation);
		
		// Switch the velocity direction
		velocity = -velocity;
	}
}

/*
Rotate the platform using deltatime 
@param float deltaTime the rate of movement using the user's FPS
@return void
*/
void AMovingPlatform::rotatePlatform(float deltaTime)
{

	// Add the rotation to the local rotation vector
	AddActorLocalRotation(angularVelocity * deltaTime);
}

