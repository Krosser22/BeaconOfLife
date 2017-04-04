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

  int32 GetAIID();
};