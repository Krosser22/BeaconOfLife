// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "BeaconOfLife.h"
#include "BeaconOfLifeGameMode.h"
#include "BeaconOfLifePlayerController.h"
#include "BeaconOfLifeCharacter.h"
#include <EngineGlobals.h>
#include <Runtime/Engine/Classes/Engine/Engine.h>

ABeaconOfLifeGameMode::ABeaconOfLifeGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = ABeaconOfLifePlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Blueprints/Characters/BP_Player"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

void ABeaconOfLifeGameMode::CreateListOfNames()
{
  Names.Add(TEXT("Daniel"));
  Names.Add(TEXT("Suso"));
  Names.Add(TEXT("Miguel"));
  Names.Add(TEXT("Popi"));
  Names.Add(TEXT("Poti"));
  Names.Add(TEXT("Charly"));
  Names.Add(TEXT("Marina"));
  Names.Add(TEXT("Mari"));
  Names.Add(TEXT("Kitone"));
  Names.Add(TEXT("Ana"));
  Names.Add(TEXT("Minerva"));
  Names.Add(TEXT("Fernando"));
  Names.Add(TEXT("David"));
  Names.Add(TEXT("Cejota"));
  Names.Add(TEXT("Yasoda"));
  Names.Add(TEXT("Cañi"));
  Names.Add(TEXT("Talon"));
  Names.Add(TEXT("Gonzalo"));
  Names.Add(TEXT("Javier"));
  Names.Add(TEXT("Krosser22"));
  Names.Add(TEXT("Uzgus"));
  Names.Add(TEXT("Sergi"));
  Names.Add(TEXT("Raul"));
  Names.Add(TEXT("Jose Luis"));
  Names.Add(TEXT("Naranjo"));
  Names.Add(TEXT("Luis"));
  Names.Add(TEXT("Clara"));
  Names.Add(TEXT("Anais"));
  Names.Add(TEXT("Jaume"));
  Names.Add(TEXT("Jorge"));
  Names.Add(TEXT("Nacho"));
  Names.Add(TEXT("Andrea"));
  Names.Add(TEXT("Diego"));
  Names.Add(TEXT("Julie"));
}

int32 ABeaconOfLifeGameMode::GetAIID()
{
  static int32 start = 0;
  GEngine->AddOnScreenDebugMessage(-1, 4.0f, FColor::Red, FString::Printf(TEXT("%d"), start));
  return start++;
}

FString ABeaconOfLifeGameMode::GetAIName()
{
  /*if (Names.Num() > 0)
  {
    return Names[0]; //FMath::RandRange(0, Names.Num() - 1)
  }
  else
  {*/
    return FString(TEXT("22"));
  //}
}