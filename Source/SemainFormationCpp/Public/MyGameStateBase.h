// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "MyGameStateBase.generated.h"

UCLASS()

class SEMAINFORMATIONCPP_API AMyGameStateBase : public AGameStateBase
{
	GENERATED_BODY()

protected:
	int32 FirstStateNumberOfKey;
	int32 FirstStateNeededNumberOfKey;
	TArray<FName> ListOfLevel;
	TMap<FName, TArray<FName>> ListOfState;
	int32 StateIndex;
	int32 LevelIndex;
	FName ActualState;
	FName ActualLevel;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void FirstStateNumberOfKeyCheck();
	void ChangeActualState();
	void ChangeActualLevel();

public:

	AMyGameStateBase();

	void UpdateState();
	void AddFirstSateKey();
	int32 GetFirstStateKey();
	int32 GetFirstStateNeededKey();
	FName GetActuaLevel();
	FName GetActualState();
	void TriggerStateChange();
};
