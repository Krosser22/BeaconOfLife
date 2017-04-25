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
#include "BeaconOfLifeGameMode.h"
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

  ABeaconOfLifeGameMode *GameMode = (ABeaconOfLifeGameMode *)GetGameInstance();
  ID = GameMode->GetAIID();
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
}

// Called to bind functionality to input
void ABeaconOfLife_AI::SetupPlayerInputComponent(class UInputComponent *InputComponent)
{
  Super::SetupPlayerInputComponent(InputComponent);
}

void ABeaconOfLife_AI::OnBeginOverlap(UPrimitiveComponent *HitComp, AActor *OtherActor, UPrimitiveComponent *OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult)
{
  AFood* food = Cast<AFood>(OtherActor);
  ADrink* drink = Cast<ADrink>(OtherActor);
  if (food)
  {
    food->enabled = false;
    food->SetActorLocation(FVector(9999.0f, 9999.0f, 9999.0f));
    Foods.Add(food);
  }
  else if (drink)
  {
    drink->enabled = false;
    drink->SetActorLocation(FVector(9999.0f, 9999.0f, 9999.0f));
    Drinks.Add(drink);
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
  
  isFamily = (AI_Partner == character) | (this == character) | (AI_Parent1 == character) | (AI_Parent2 == character);

  for (int32 i = 0; i < AI_Children.Num() && !isFamily; ++i)
  {
    isFamily = (AI_Children[i] == character);
  }

  return isFamily;
}

void ABeaconOfLife_AI::AddMessage(FAIMessage message)
{
  bool found = false;
  for (int32 i = 0; i < Messages.Num() && !found; ++i)
  {
    if (Messages[i].MessageEnum == message.MessageEnum && Messages[i].Sender == message.Sender) found = true;
  }

  if (!found) Messages.Add(message);
}

void ABeaconOfLife_AI::Talk(ABeaconOfLife_AI *AI)
{
  bool found = false;
  FFriend *theFriend = nullptr;
  for (int32 i = 0; i < Friends.Num() && !found; ++i)
  {
    if (Friends[i].Friend == AI)
    {
      found = true;
      theFriend = &Friends[i];
    }
  }

  if (!found)
  {
    FFriend newFriend;
    theFriend = &newFriend;
    newFriend.Friend = AI;
    Friends.Add(newFriend);
    //TODO: Add random numbers with in a range
    /*newFriend.FriendshipGainedPerInteraction = 0.08f;
    newFriend.FriendshipLostPerInteraction = 0.1f;
    newFriend.FriendshipLostPerTime = 0.001f;
    newFriend.AmountToFallInLove = 90.22f;*/
  }

  theFriend->Friendship += theFriend->FriendshipGainedPerInteraction;
  PhysiologicalStats.Drink *= 0.9f;
  PhysiologicalStats.Food *= 0.95f;

  if (theFriend->Friendship >= theFriend->AmountToFallInLove)
  {
    if (!theFriend->Friend->AI_Partner && !AI_Partner)
    {
      theFriend->Friend->AI_Partner = this;
      AI_Partner = theFriend->Friend;
    }
  }
}

void ABeaconOfLife_AI::Procreate(ABeaconOfLife_AI *AI)
{
  bool found = false;
  FFriend *theFriend = nullptr;
  for (int32 i = 0; i < Friends.Num() && !found; ++i)
  {
    if (Friends[i].Friend == AI)
    {
      found = true;
      theFriend = &Friends[i];
    }
  }

  //If is procreating it must be on the friend list but lets add this just in case it is not
  if (!found)
  {
    FFriend newFriend;
    theFriend = &newFriend;
    newFriend.Friend = AI;
    //TODO: Add random numbers with in a range
    /*newFriend.FriendshipGainedPerInteraction = 0.08f;
    newFriend.FriendshipLostPerInteraction = 0.1f;
    newFriend.FriendshipLostPerTime = 0.001f;
    newFriend.AmountToFallInLove = 90.22f;*/
  }

  theFriend->Friendship += theFriend->FriendshipGainedPerInteraction * 2.0f;
  PhysiologicalStats.Drink *= 0.7f;
  PhysiologicalStats.Food *= 0.6f;
}

void ABeaconOfLife_AI::SetJob(EJob newJob)
{
  JobStats.job = newJob;

  switch (JobStats.job)
  {
  case EJob::Job_Cleaner:
    JobStats.level = 1;
    JobStats.TimeToStartWorking = 0.0f;
    JobStats.AmountOfTimeToWork = 4.0f;
    break;
  case EJob::Job_Farmer:
    JobStats.level = 1;
    JobStats.TimeToStartWorking = 4.0f;
    JobStats.AmountOfTimeToWork = 4.0f;
    break;
  case EJob::Job_Vendor:
    JobStats.level = 1;
    JobStats.TimeToStartWorking = 8.0f;
    JobStats.AmountOfTimeToWork = 4.0f;
    break;
  case EJob::Job_Doctor:
    JobStats.level = 1;
    JobStats.TimeToStartWorking = 12.0f;
    JobStats.AmountOfTimeToWork = 4.0f;
    break;
  case EJob::Job_FilmWorker:
    JobStats.level = 1;
    JobStats.TimeToStartWorking = 16.0f;
    JobStats.AmountOfTimeToWork = 4.0f;
    break;
  case EJob::Job_Chef:
    JobStats.level = 1;
    JobStats.TimeToStartWorking = 20.0f;
    JobStats.AmountOfTimeToWork = 4.0f;
    break;
  case EJob::Job_Librarian:
    JobStats.level = 1;
    JobStats.TimeToStartWorking = 22.0f;
    JobStats.AmountOfTimeToWork = 4.0f;
    break;
  default:
    break;
  }
}

void ABeaconOfLife_AI::SetJobBuilding(ABuildingBase *building)
{
  JobStats.jobBuilding = building;
}