// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "BeaconOfLife_AI.generated.h"

UCLASS()
class BEACONOFLIFE_API ABeaconOfLife_AI : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABeaconOfLife_AI();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;
};
