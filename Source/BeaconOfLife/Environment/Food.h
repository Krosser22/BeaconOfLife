/**
*** ////////////////////////////////////////////
*** //// Autor: Juan Daniel Laserna Condado ////
*** //// Email: S6106112@live.tees.ac.uk    ////
*** //// Email: condadodaniel@hotmail.com   ////
*** ////                2017                ////
*** ////////////////////////////////////////////
**/
#pragma once

#include "Environment/Item.h"
#include "Food.generated.h"

UCLASS()
class BEACONOFLIFE_API AFood : public AItem
{
  GENERATED_BODY()

public:
  // Sets default values for this actor's properties
  AFood();

  // Amount of food obtainable from this food
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Food")
    float AmountOfPower;

  // Time needed to eat this food
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Food")
    float TimeToEat;
};