// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Grabber.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ROOMESCAPE_API UGrabber : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrabber();

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	// Called when the game starts
	virtual void BeginPlay() override;

protected:

	UFUNCTION(BlueprintCallable, Category = "Input")
	void Grab();

	UFUNCTION(BlueprintCallable, Category = "Input")
	void Release();

private:

	float Reach = 100.0;
	UPhysicsHandleComponent* PhysicsHandle = nullptr;
	FVector PlayerViewPointLocation;
	FRotator PlayerViewPointRotation;

	void FindPhysicsHandleComponent();
	FVector GetPlayerGrabVector();
	FHitResult GetFirstPhysicsBodyInReach();
		
};
