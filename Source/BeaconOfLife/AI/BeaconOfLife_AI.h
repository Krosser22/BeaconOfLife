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

  //HEAL
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
    float Heal;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
    float AmountToBeDying;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
    float DyingPerTimeWhenHungry;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
    float DyingPerTimeWhenThirty;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
    float DyingPerTimeWhenSleepy;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
    float DyingPerTimeWhenDying;

  //Constructor
  FPhysiologicalStats()
  {
    Food = 100.0f;
    AmountToBeHungry = 25.0f;
    HungryPerTime = 0.08f;

    Drink = 100.0f;
    AmountToBeThirsty = 30.0f;
    ThirstyPerTime = 0.09f;

    Sleep = 100.0f;
    AmountToBeSleepy = 20.0f;
    SleepyPerTime = 0.04f;
    AmountToSleepNow = 10.0f;

    Heal = 100.0f;
    AmountToBeDying = 22.22f;
    DyingPerTimeWhenHungry = 0.08f;
    DyingPerTimeWhenThirty = 0.09f;
    DyingPerTimeWhenSleepy = 0.04f;
    DyingPerTimeWhenDying = 0.22f;
  }
};

UENUM(BlueprintType)
enum class EMessage : uint8
{
  Message_None UMETA(DisplayName = "None"),
  Message_RequestTalk UMETA(DisplayName = "RequestTalk"),
  Message_AcceptTalk UMETA(DisplayName = "AcceptTalk"),
  Message_Talk UMETA(DisplayName = "Talk"),
  Message_RequestProcreate UMETA(DisplayName = "RequestProcreate"),
  Message_AcceptProcreate UMETA(DisplayName = "AcceptProcreate"),
  Message_Procreate UMETA(DisplayName = "Procreate")
};

USTRUCT(BlueprintType)
struct FAIMessage
{
  GENERATED_BODY();

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Social")
    EMessage MessageEnum;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Social")
    ABeaconOfLife_AI *Sender;

  //Constructor
  FAIMessage()
  {
    MessageEnum = EMessage::Message_None;
    Sender = nullptr;
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

  // Return if the AI is dying
  UFUNCTION(BlueprintCallable, Category = "PhysiologicalStats")
    bool IsDying();

  // Make the AI eat food
  UFUNCTION(BlueprintCallable, Category = "PhysiologicalStats")
    void EatFood(AFood *food);

  // Make the AI drink a drink
  UFUNCTION(BlueprintCallable, Category = "PhysiologicalStats")
    void DrinkDrink(ADrink *drink);

  // Make the AI sleep
  UFUNCTION(BlueprintCallable, Category = "PhysiologicalStats")
    void Sleep(float amountObtainable);

  // Make the AI be healed
  UFUNCTION(BlueprintCallable, Category = "PhysiologicalStats")
    void Heal(float amountObtainable);

  // Get food from the inventory
  UFUNCTION(BlueprintCallable, Category = "Inventory")
    AFood *GetFoodFromInventory();

  // Get drink from the inventory
  UFUNCTION(BlueprintCallable, Category = "Inventory")
    ADrink *GetDrinkFromInventory();

  // Add food to the inventory
  UFUNCTION(BlueprintCallable, Category = "Inventory")
    void AddFoodToInventory(AFood *food);

  // Add drink to the inventory
  UFUNCTION(BlueprintCallable, Category = "Inventory")
    void AddDrinkToInventory(ADrink *drink);

  // Add wood to the inventory
  UFUNCTION(BlueprintCallable, Category = "Inventory")
    void AddWoodToInventory(int amount);

  // Add rock to the inventory
  UFUNCTION(BlueprintCallable, Category = "Inventory")
    void AddRockToInventory(int amount);

  // Return the amount of rocks on the inventory
  UFUNCTION(BlueprintCallable, Category = "Inventory")
    int GetAmountOfRocksOnInventory();

  // Return the amount of woods on the inventory
  UFUNCTION(BlueprintCallable, Category = "Inventory")
    int GetAmountOfWoodsOnInventory();

  // Return if a character is family (partner or child)
  UFUNCTION(BlueprintCallable, Category = "Social")
    bool IsFamily(ABeaconOfLife_AI *character);

  // Return if a character is family (partner or child)
  UFUNCTION(BlueprintCallable, Category = "Social")
    void AddMessage(FAIMessage message);

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

  // The parent1 of this character
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Social")
    ABeaconOfLife_AI *AI_Parent1;

  // The parent2 of this character
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Social")
    ABeaconOfLife_AI *AI_Parent2;

  // The home of this character
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Building")
    ABuildingBase *Home;

private:
  // Box Collision
  UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"), Category = "Collision")
    UBoxComponent* CollisionComponent;

  // The inventory of the AI
  TArray<AItem *> Inventory;

  // Rocks on the inventory
  UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"), Category = "Inventory")
    int Rocks;

  // Woods on the inventory
  UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"), Category = "Inventory")
    int Woods;

  // Messages send by other AI
  UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"), Category = "Social")
    TArray<FAIMessage> Messages;
};