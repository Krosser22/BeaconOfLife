/**
*** ////////////////////////////////////////////
*** //// Autor: Juan Daniel Laserna Condado ////
*** //// Email: S6106112@live.tees.ac.uk    ////
*** //// Email: condadodaniel@hotmail.com   ////
*** ////                2017                ////
*** ////////////////////////////////////////////
**/
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
  virtual void Tick(float DeltaSeconds) override;

  // Time to build this building
  UPROPERTY(BlueprintReadWrite, Category = "Time")
    float TimeToBuild = 4.0f;
};