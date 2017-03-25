/**
*** ////////////////////////////////////////////
*** //// Autor: Juan Daniel Laserna Condado ////
*** //// Email: S6106112@live.tees.ac.uk    ////
*** //// Email: condadodaniel@hotmail.com   ////
*** ////                2017                ////
*** ////////////////////////////////////////////
**/
#include "BeaconOfLife.h"
#include "BeaconOfLife_AI.h"
#include <EngineGlobals.h>
#include <Runtime/Engine/Classes/Engine/Engine.h>

// Sets default values
ABeaconOfLife_AI::ABeaconOfLife_AI()
{
  // Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
  PrimaryActorTick.bCanEverTick = true;

  // Create Tripwire Collision
  CollisionComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollision"));
  CollisionComponent->InitBoxExtent(FVector(10, 10, 10));
  CollisionComponent->SetupAttachment(RootComponent);
  CollisionComponent->OnComponentBeginOverlap.AddDynamic(this, &ABeaconOfLife_AI::OnBeginOverlap);

  Money = 100;
}

// Called when the game starts or when spawned
void ABeaconOfLife_AI::BeginPlay()
{
  Super::BeginPlay();
}

// Called every frame
void ABeaconOfLife_AI::Tick(float DeltaTime)
{
  Super::Tick(DeltaTime);

  PhysiologicalStats.Food -= PhysiologicalStats.HungryPerTime * DeltaTime;
  PhysiologicalStats.Drink -= PhysiologicalStats.ThirstyPerTime * DeltaTime;
  PhysiologicalStats.Sleep -= PhysiologicalStats.SleepyPerTime * DeltaTime;
  PhysiologicalStats.Heal -= PhysiologicalStats.DyingPerTimeWhenHungry * DeltaTime * (PhysiologicalStats.Food < PhysiologicalStats.AmountToBeHungry);
  PhysiologicalStats.Heal -= PhysiologicalStats.DyingPerTimeWhenThirty * DeltaTime * (PhysiologicalStats.Drink < PhysiologicalStats.AmountToBeThirsty);
  PhysiologicalStats.Heal -= PhysiologicalStats.DyingPerTimeWhenSleepy * DeltaTime * (PhysiologicalStats.Sleep < PhysiologicalStats.AmountToBeSleepy);
  PhysiologicalStats.Heal -= PhysiologicalStats.DyingPerTimeWhenDying * DeltaTime * (PhysiologicalStats.Heal < PhysiologicalStats.AmountToBeDying);
  //GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Yellow, FString::Printf(TEXT("%f  || %f"), PhysiologicalStats.Food, PhysiologicalStats.AmountToBeHungry));
}

// Called to bind functionality to input
void ABeaconOfLife_AI::SetupPlayerInputComponent(class UInputComponent *InputComponent)
{
  Super::SetupPlayerInputComponent(InputComponent);
}

void ABeaconOfLife_AI::OnBeginOverlap(UPrimitiveComponent *HitComp, AActor *OtherActor, UPrimitiveComponent *OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult)
{
  AItem* item = Cast<AItem>(OtherActor);
  if (item)
  {
    Inventory.Add(item);
    item->SetActorLocation(FVector(9999.0f, 9999.0f, 9999.0f));
    item->enabled = false;
  }
}

bool ABeaconOfLife_AI::IsHungry()
{
  return (PhysiologicalStats.Food < PhysiologicalStats.AmountToBeHungry);
}

bool ABeaconOfLife_AI::IsThirsty()
{
  return (PhysiologicalStats.Drink < PhysiologicalStats.AmountToBeThirsty);
}

bool ABeaconOfLife_AI::IsSleepy()
{
  return (PhysiologicalStats.Sleep < PhysiologicalStats.AmountToBeSleepy);
}

bool ABeaconOfLife_AI::IsDying()
{
  return (PhysiologicalStats.Heal < PhysiologicalStats.AmountToBeDying);
}

void ABeaconOfLife_AI::EatFood(AFood *food)
{
  //GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Yellow, FString::Printf(TEXT("%f  || %f"), PhysiologicalStats.Food, PhysiologicalStats.AmountToBeHungry));
  PhysiologicalStats.Food += food->AmountOfPower;
}

void ABeaconOfLife_AI::DrinkDrink(ADrink *drink)
{
  PhysiologicalStats.Drink += drink->AmountOfPower;
}

void ABeaconOfLife_AI::Sleep(float amountObtainable)
{
  PhysiologicalStats.Sleep += amountObtainable;
}

void ABeaconOfLife_AI::Heal(float amountObtainable)
{
  PhysiologicalStats.Heal += amountObtainable;
}

AFood *ABeaconOfLife_AI::GetFoodFromInventory()
{
  bool foodFound = false;
  AFood* food = nullptr;
  for (int32 i = 0; i < Inventory.Num() && !foodFound; ++i)
  {
    food = Cast<AFood>(Inventory[i]);
    if (food)
    {
      foodFound = true;

      food->Amount--;
      if (food->Amount <= 0)
      {
        Inventory.RemoveAt(i);
      }
    }
  }
  return food;
}

ADrink *ABeaconOfLife_AI::GetDrinkFromInventory()
{
  bool drinkFound = false;
  ADrink* drink = nullptr;
  for (int32 i = 0; i < Inventory.Num() && !drinkFound; ++i)
  {
    drink = Cast<ADrink>(Inventory[i]);
    if (drink)
    {
      drinkFound = true;

      drink->Amount--;
      if (drink->Amount <= 0)
      {
        Inventory.RemoveAt(i);
      }
    }
  }
  return drink;
}

void ABeaconOfLife_AI::AddFoodToInventory(AFood *food)
{
  Inventory.Add(food);
}

void ABeaconOfLife_AI::AddDrinkToInventory(ADrink *drink)
{
  Inventory.Add(drink);
}

void ABeaconOfLife_AI::AddWoodToInventory(int amount)
{
  Woods += amount;
}

void ABeaconOfLife_AI::AddRockToInventory(int amount)
{
  Rocks += amount;
}

int ABeaconOfLife_AI::GetAmountOfRocksOnInventory()
{
  return Rocks;
}

int ABeaconOfLife_AI::GetAmountOfWoodsOnInventory()
{
  return Woods;
}

bool ABeaconOfLife_AI::IsFamily(ABeaconOfLife_AI *character)
{
  bool isFamily = false;
  
  isFamily = (AI_Partner == character) | (this == character);

  for (int32 i = 0; i < AI_Children.Num() && !isFamily; ++i)
  {
    isFamily = (AI_Children[i] == character);
  }

  return isFamily;
}