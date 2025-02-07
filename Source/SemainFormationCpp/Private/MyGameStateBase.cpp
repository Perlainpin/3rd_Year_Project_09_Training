// Fill out your copyright notice in the Description page of Project Settings.

#include "MyGameStateBase.h"

AMyGameStateBase::AMyGameStateBase() 
{
	LevelIndex = 0;
	StateIndex = 0;
	ListOfLevel = {
		TEXT("EscapeTheOrkCamp"),
		TEXT("PathToVictory")
	};
	ListOfState = {
		{ListOfLevel[0],{TEXT("FindTheKeys"),TEXT("OpenTheGate")}},
		{ListOfLevel[1], {TEXT("Go")}}
	};
	UE_LOG(LogTemp, Log, TEXT("Game State Start"));
	UE_LOG(LogTemp, Warning, TEXT("My Name: %s"), *ListOfLevel[0].ToString());
}

void AMyGameStateBase::BeginPlay()
{
	Super::BeginPlay();
};

void AMyGameStateBase::UpdateState() {
	if (this) {
		ChangeActualState();
		ChangeActualLevel();
		FirstStateNumberOfKeyCheck();

		UE_LOG(LogTemp, Log, TEXT("Game State Update"));
	}
	else {
		UE_LOG(LogTemp, Error, TEXT("gamestate do not exist"));
	}
	
}

void AMyGameStateBase::ChangeActualState() {
	if (StateIndex < ListOfState[ListOfLevel[LevelIndex]].Num()) {
		LevelIndex++;
		StateIndex = 0;
	}
	ActualState = ListOfState[ListOfLevel[LevelIndex]][StateIndex];
	UE_LOG(LogTemp, Log, TEXT("ChangeState"));
};

void AMyGameStateBase::ChangeActualLevel() {
	ActualLevel = ListOfLevel[LevelIndex];
	UE_LOG(LogTemp, Log, TEXT("ChangeLevel"));
}

void AMyGameStateBase::AddFirstSateKey(){
	if (ActualState == ListOfState[TEXT("EscapeTheOrkCamp")][0]) {
		FirstStateNumberOfKey++;
		UE_LOG(LogTemp, Log, TEXT("AddKey"));
	};
};

int32 AMyGameStateBase::GetFirstStateKey() {
	return FirstStateNumberOfKey;
};

FName AMyGameStateBase::GetActuaLevel() {
	return ActualLevel;
};

FName AMyGameStateBase::GetActualState() {
	return ActualState;
};

void AMyGameStateBase::FirstStateNumberOfKeyCheck() {
	if (ActualState == ListOfState[TEXT("VillageInTheTree")][0]) {
		if (FirstStateNumberOfKey == FirstStateNeededNumberOfKey) {
			StateIndex++;
			UE_LOG(LogTemp, Log, TEXT("ChangeStateAfterKey"));
		}
	};
};

void AMyGameStateBase::TriggerStateChange() {
	StateIndex++;
}