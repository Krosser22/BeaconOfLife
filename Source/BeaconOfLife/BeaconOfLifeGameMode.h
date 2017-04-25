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

  // Add all the available names to the list of names
  UFUNCTION(BlueprintCallable, Category = "General")
    void CreateListOfNames();

  // Gets the next ID to give to an AI
  UFUNCTION(BlueprintCallable, Category = "General")
    int32 GetAIID();

  // The time of the day
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Time")
    float TimeOfDay;

  // The list of names of the AI
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "General")
    TArray<FString> Names;
};