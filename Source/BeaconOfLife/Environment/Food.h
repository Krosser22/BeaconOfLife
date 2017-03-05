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
#include "Item.h"
#include "Food.generated.h"

UCLASS()
class BEACONOFLIFE_API AFood : public AItem
{
  GENERATED_BODY()

public:
  // Sets default values for this actor's properties
  AFood();

  // Called when the game starts or when spawned
  virtual void BeginPlay() override;

  // Called every frame
  virtual void Tick(float DeltaSeconds) override;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Food")
    float AmountOfPower;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Food")
    float TimeToEat;
};