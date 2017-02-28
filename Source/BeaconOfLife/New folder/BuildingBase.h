// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "BuildingBase.generated.h"

UCLASS()
class BEACONOFLIFE_API ABuildingBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABuildingBase();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

  // Time to build this building
  UPROPERTY(BlueprintReadWrite, Category = "Time")
    float TimeToBuild = 4.0f;
};