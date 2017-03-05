/**
*** ////////////////////////////////////////////
*** //// Autor: Juan Daniel Laserna Condado ////
*** //// Email: S6106112@live.tees.ac.uk    ////
*** //// Email: condadodaniel@hotmail.com   ////
*** ////                2017                ////
*** ////////////////////////////////////////////
**/
#pragma once

#include "GameFramework/Character.h"
#include "BeaconOfLife_AI.generated.h"

USTRUCT(BlueprintType)
struct FPhysiologicalStats
{
  GENERATED_BODY();

  //FOOD
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
    float Food;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
    float AmountToBeHungry;

  //WATER
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
    float Water;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
    float AmountToBeThirsty;

  //SLEEP
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
    float Sleep;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
    float AmountToBeSleepy;

  //Constructor
  FPhysiologicalStats()
  {
    Food = 0.0f;
    AmountToBeHungry = 22.0f;

    Water = 100.0f;
    AmountToBeThirsty = 22.0f;

    Sleep = 100.0f;
    AmountToBeSleepy = 22.0f;
  }
};

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
  virtual void Tick(float DeltaSeconds) override;

  // Called to bind functionality to input
  virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

  //Return if the AI is hungry
  UFUNCTION(BlueprintCallable, Category = "Stats")
    bool IsHungry();

  //Return if the AI is thirsty
  UFUNCTION(BlueprintCallable, Category = "Stats")
    bool IsThirsty();

  //Return if the AI is sleepy
  UFUNCTION(BlueprintCallable, Category = "Stats")
    bool IsSleepy();

  UFUNCTION(BlueprintCallable, Category = "Stats")
    bool EatFood();

private:
  //Physiological stats
  FPhysiologicalStats PhysiologicalStats;
};