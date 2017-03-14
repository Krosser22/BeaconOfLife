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
#include "Building/BuildingBase.h"
#include "Environment/Food.h"
#include "Environment/Item.h"
#include "Environment/Drink.h"
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

  //DRINK
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
    float Drink;
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
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
    float AmountToSleepNow;

  //Constructor
  FPhysiologicalStats()
  {
    Food = 100.0f;
    AmountToBeHungry = 22.0f;
    HungryPerTime = 0.08f;

    Drink = 100.0f;
    AmountToBeThirsty = 30.0f;
    ThirstyPerTime = 0.09f;

    Sleep = 100.0f;
    AmountToBeSleepy = 22.0f;
    SleepyPerTime = 1.05f;
    AmountToSleepNow = 10.0f;
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
  UFUNCTION(BlueprintCallable, Category = "PhysiologicalStats")
    bool IsHungry();

  // Return if the AI is thirsty
  UFUNCTION(BlueprintCallable, Category = "PhysiologicalStats")
    bool IsThirsty();

  // Return if the AI is sleepy
  UFUNCTION(BlueprintCallable, Category = "PhysiologicalStats")
    bool IsSleepy();

  // Make the AI eat food from the inventory
  UFUNCTION(BlueprintCallable, Category = "PhysiologicalStats")
    void EatFood(AFood *food);

  // Make the AI drink a drink from the inventory
  UFUNCTION(BlueprintCallable, Category = "PhysiologicalStats")
    void DrinkDrink(ADrink *drink);

  // Make the AI sleep from the inventory
  UFUNCTION(BlueprintCallable, Category = "PhysiologicalStats")
    void Sleep(float amountObtainable);

  // Get food from the inventory
  UFUNCTION(BlueprintCallable, Category = "PhysiologicalStats")
    AFood *GetFoodFromInventory();

  // Get drink from the inventory
  UFUNCTION(BlueprintCallable, Category = "PhysiologicalStats")
    ADrink *GetDrinkFromInventory();

  // Add food to the inventory
  UFUNCTION(BlueprintCallable, Category = "PhysiologicalStats")
    void AddFoodToInventory(AFood *food);

  // Add drink to the inventory
  UFUNCTION(BlueprintCallable, Category = "PhysiologicalStats")
    void AddDrinkToInventory(ADrink *drink);

  // Return if a character is family (partner or child)
  UFUNCTION(BlueprintCallable, Category = "Social")
    bool IsFamily(ABeaconOfLife_AI *character);

  // Physiological stats
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PhysiologicalStats")
    FPhysiologicalStats PhysiologicalStats;

  // Money stored on this AI
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "General")
    int Money;

  // The partner of this character
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Social")
    ABeaconOfLife_AI *AI_Partner;

  // The children of this character
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Social")
    TArray<ABeaconOfLife_AI *> AI_Children;

  // The home of this character
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Building")
    ABuildingBase *Home;

private:
  // Box Collision
  UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"), Category = "Collision")
    UBoxComponent* CollisionComponent;

  // The inventory of the AI
  TArray<AItem *> Inventory;
};