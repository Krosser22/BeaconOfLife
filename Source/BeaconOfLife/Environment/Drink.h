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
#include "Drink.generated.h"

UCLASS()
class BEACONOFLIFE_API ADrink : public AItem
{
	GENERATED_BODY()

public:
  // Sets default values for this actor's properties
  ADrink();

  // Called when the game starts or when spawned
  virtual void BeginPlay() override;

  // Called every frame
  virtual void Tick(float DeltaSeconds) override;

  // Amount of drink obtainable from this drink
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Drink")
    float AmountOfPower;

  // Time needed to drink this drink
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Drink")
    float TimeToDrink;
};