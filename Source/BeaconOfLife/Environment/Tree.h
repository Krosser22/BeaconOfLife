/**
*** ////////////////////////////////////////////
*** //// Autor: Juan Daniel Laserna Condado ////
*** //// Email: S6106112@live.tees.ac.uk    ////
*** //// Email: condadodaniel@hotmail.com   ////
*** ////                2017                ////
*** ////////////////////////////////////////////
**/
#pragma once

#include "GameFramework/Actor.h"
#include "Tree.generated.h"

UCLASS()
class BEACONOFLIFE_API ATree : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATree();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
  virtual void Tick(float DeltaSeconds) override;

  //Amount of wood obtainable from this tree
  UPROPERTY(BlueprintReadWrite, Category = "Tree")
    int WoodAmount = 10;

  //Time to get one portion of wood from this tree
  UPROPERTY(BlueprintReadWrite, Category = "Tree")
    int TimeToGetOnePortion = 1.0f;
};