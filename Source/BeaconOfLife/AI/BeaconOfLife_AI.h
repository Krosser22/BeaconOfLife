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
#include "Environment/Food.h"
#include "Environment/Item.h"
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
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
    float HungryPerTime;

  //WATER
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
    float Water;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
    float AmountToBeThirsty;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
    float ThirstyPerTime;

  //SLEEP
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
    float Sleep;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
    float AmountToBeSleepy;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
    float SleepyPerTime;

  //Constructor
  FPhysiologicalStats()
  {
    Food = 0.0f;
    AmountToBeHungry = 22.0f;
    HungryPerTime = 1.0f;

    Water = 0.0f;
    AmountToBeThirsty = 22.0f;
    ThirstyPerTime = 1.0f;

    Sleep = 0.0f;
    AmountToBeSleepy = 22.0f;
    SleepyPerTime = 1.0f;
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
  virtual void SetupPlayerInputComponent(class UInputComponent *InputComponent) override;

  // Overlap
  UFUNCTION()
    virtual void OnBeginOverlap(class UPrimitiveComponent *HitComp, class AActor *OtherActor, class UPrimitiveComponent *OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult);

  // Return if the AI is hungry
  UFUNCTION(BlueprintCallable, Category = "Stats")
    bool IsHungry();

  // Return if the AI is thirsty
  UFUNCTION(BlueprintCallable, Category = "Stats")
    bool IsThirsty();

  // Return if the AI is sleepy
  UFUNCTION(BlueprintCallable, Category = "Stats")
    bool IsSleepy();

  // Make the AI eat food from the inventory
  UFUNCTION(BlueprintCallable, Category = "Stats")
    bool EatFood(AFood *food);

  // Make the AI drink water from the inventory
  UFUNCTION(BlueprintCallable, Category = "Stats")
    bool DrinkWater();

  // Make the AI sleep from the inventory
  UFUNCTION(BlueprintCallable, Category = "Stats")
    bool Sleep();

  UFUNCTION(BlueprintCallable, Category = "Stats")
    AFood *getFoodFromInventory();

private:
  // Box Collision
  UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"), Category = "Collision")
    UBoxComponent* CollisionComponent;

  // Physiological stats
  FPhysiologicalStats PhysiologicalStats;

  // The inventory of the AI
  TArray<AItem *> Inventory;
};