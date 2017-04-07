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
  PrimaryActorTick.bCanEverTick = false;

  enabled = true;
  BuyPrice = 10;
}