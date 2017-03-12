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
#include "Item.generated.h"

UCLASS()
class BEACONOFLIFE_API AItem : public AActor
{
  GENERATED_BODY()

public:
  // Sets default values for this actor's properties
  AItem();

  // Called when the game starts or when spawned
  virtual void BeginPlay() override;

  // Called every frame
  virtual void Tick(float DeltaSeconds) override;

  // Overlap
  UFUNCTION()
    virtual void OnBeginOverlap(class UPrimitiveComponent *HitComp, class AActor *OtherActor, class UPrimitiveComponent *OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult);

  // If the element is enabled
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
    bool enabled;

  // Max amount of this element
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
    int MaxAmount;

  // Actual amount of this element
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
    int Amount;

  // The price when buying the item
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
    int BuyPrice;

protected:
  // Box Collision
  UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"), Category = "Collision")
    UBoxComponent* CollisionComponent;

  // Mesh
  UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"), Category = "Mesh")
    UStaticMeshComponent* MeshComponent;
};