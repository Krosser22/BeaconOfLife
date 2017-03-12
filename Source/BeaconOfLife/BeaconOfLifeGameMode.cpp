// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "BeaconOfLife.h"
#include "BeaconOfLifeGameMode.h"
#include "BeaconOfLifePlayerController.h"
#include "BeaconOfLifeCharacter.h"

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