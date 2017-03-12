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

  // Create Tripwire Mesh
  MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
  MeshComponent->SetupAttachment(RootComponent);

  // Create Tripwire Collision
  CollisionComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollision"));
  CollisionComponent->InitBoxExtent(FVector(10, 10, 10));
  CollisionComponent->SetupAttachment(MeshComponent);
  CollisionComponent->OnComponentBeginOverlap.AddDynamic(this, &AItem::OnBeginOverlap);

  enabled = true;
  MaxAmount = 100;
  Amount = 1;
  BuyPrice = 10;
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

void AItem::OnBeginOverlap(UPrimitiveComponent *HitComp, AActor *OtherActor, UPrimitiveComponent *OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult)
{
  //OtherActor->Destroy();

  /*AItem* item = Cast<AItem>(OtherActor);
  if (item)
  {
  item->Destroy();
  }*/
}