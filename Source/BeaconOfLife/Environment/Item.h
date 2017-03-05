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

  // Called when the game starts or when spawned
  virtual void BeginPlay() override;

  // Called every frame
  virtual void Tick(float DeltaSeconds) override;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
    float MaxAmount;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
    float Amount;
};