// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.
#pragma once
#include "GameFramework/GameMode.h"
#include "BeaconOfLifeGameMode.generated.h"

UCLASS(minimalapi)
class ABeaconOfLifeGameMode : public AGameMode
{
	GENERATED_BODY()

public:
	ABeaconOfLifeGameMode();

  // Gets the next ID to give to an AI
  int32 GetAIID();

  // The time of the day
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Time")
    float TimeOfDay;
};