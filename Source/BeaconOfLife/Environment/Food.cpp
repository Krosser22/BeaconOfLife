/**
*** ////////////////////////////////////////////
*** //// Autor: Juan Daniel Laserna Condado ////
*** //// Email: S6106112@live.tees.ac.uk    ////
*** //// Email: condadodaniel@hotmail.com   ////
*** ////                2017                ////
*** ////////////////////////////////////////////
**/
#include "BeaconOfLife.h"
#include "Food.h"

// Sets default values
AFood::AFood()
{
  // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
  PrimaryActorTick.bCanEverTick = true;

  AmountOfPower = 40.0f;
  TimeToEat = 2.0f;
}

// Called when the game starts or when spawned
void AFood::BeginPlay()
{
  Super::BeginPlay();
}

// Called every frame
void AFood::Tick(float DeltaTime)
{
  Super::Tick(DeltaTime);
}