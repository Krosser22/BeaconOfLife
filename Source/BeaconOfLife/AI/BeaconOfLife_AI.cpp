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
  PhysiologicalStats.Water -= PhysiologicalStats.ThirstyPerTime * DeltaTime;
  PhysiologicalStats.Sleep -= PhysiologicalStats.SleepyPerTime * DeltaTime;
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
    item->SetActorLocation(FVector(9999, 9999, 9999));
  }
}

bool ABeaconOfLife_AI::IsHungry()
{
  return (PhysiologicalStats.Food < PhysiologicalStats.AmountToBeHungry);
}

bool ABeaconOfLife_AI::IsThirsty()
{
  return (PhysiologicalStats.Water < PhysiologicalStats.AmountToBeThirsty);
}

bool ABeaconOfLife_AI::IsSleepy()
{
  return (PhysiologicalStats.Sleep < PhysiologicalStats.AmountToBeSleepy);
}

bool ABeaconOfLife_AI::EatFood(AFood *food)
{
  //GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Yellow, FString::Printf(TEXT("%f  || %f"), PhysiologicalStats.Food, PhysiologicalStats.AmountToBeHungry));
  PhysiologicalStats.Food += food->AmountOfPower;
  return true;
}

bool ABeaconOfLife_AI::DrinkWater()
{
  PhysiologicalStats.Water = 100.0f;
  return true;
}

bool ABeaconOfLife_AI::Sleep()
{
  PhysiologicalStats.Sleep = 100.0f;
  return true;
}

AFood *ABeaconOfLife_AI::getFoodFromInventory()
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