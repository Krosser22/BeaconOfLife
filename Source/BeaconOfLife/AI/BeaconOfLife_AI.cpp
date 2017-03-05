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
}

// Called to bind functionality to input
void ABeaconOfLife_AI::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
  Super::SetupPlayerInputComponent(InputComponent);
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

bool ABeaconOfLife_AI::EatFood()
{
  //GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Yellow, FString::Printf(TEXT("%f  || %f"), PhysiologicalStats.Food, PhysiologicalStats.AmountToBeHungry));
  PhysiologicalStats.Food = 100.0f;
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