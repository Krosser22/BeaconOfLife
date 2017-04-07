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
#include "Item.generated.h"

UCLASS()
class BEACONOFLIFE_API AItem : public AActor
{
  GENERATED_BODY()

public:
  // Sets default values for this actor's properties
  AItem();

  // If the element is enabled
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
    bool enabled;

  // The price when buying the item
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
    int BuyPrice;
};