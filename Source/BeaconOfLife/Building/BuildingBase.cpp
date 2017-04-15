/**
*** ////////////////////////////////////////////
*** //// Autor: Juan Daniel Laserna Condado ////
*** //// Email: S6106112@live.tees.ac.uk    ////
*** //// Email: condadodaniel@hotmail.com   ////
*** ////                2017                ////
*** ////////////////////////////////////////////
**/
#include "BeaconOfLife.h"
#include "BuildingBase.h"

// Sets default values
ABuildingBase::ABuildingBase()
{
  PrimaryActorTick.bCanEverTick = false;
}

void ABuildingBase::SetCostToBuild(int rocks, int woods)
{
  RockNeededToBuild = rocks;
  WoodNeededToBuild = woods;
}