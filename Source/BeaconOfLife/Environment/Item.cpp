/**
*** ////////////////////////////////////////////
*** //// Autor: Juan Daniel Laserna Condado ////
*** //// Email: S6106112@live.tees.ac.uk    ////
*** //// Email: condadodaniel@hotmail.com   ////
*** ////                2017                ////
*** ////////////////////////////////////////////
**/
#include "BeaconOfLife.h"
#include "Item.h"

// Sets default values
AItem::AItem()
{
  // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
  PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AItem::BeginPlay()
{
  Super::BeginPlay();
}

// Called every frame
void AItem::Tick(float DeltaTime)
{
  Super::Tick(DeltaTime);
}