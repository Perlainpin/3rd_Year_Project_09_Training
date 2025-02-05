// Fill out your copyright notice in the Description page of Project Settings.

#include "MyGameStateBase.h"

void AMyGameStateBase::BeginPlay() {
	LevelIndex = 0;
	StateIndex = 0;
	ListOfLevel = {
		TEXT("VillageInTheTree"),
		TEXT("PathToVictory")
	};
	ListOfState = {
		{ListOfLevel[0],{TEXT("FindTheKeys"),TEXT("OpenThe")}},
		{ListOfLevel[1], {TEXT("Go")}}
	};
	UE_LOG(LogTemp, Log, TEXT("Game State Start"));
};

void AMyGameStateBase::Tick(float DeltaTime) {
	FirstStateNulberOfKeyCheck();
	ChangeActualState();
	ChangeActualLevel();
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
	if (ActualState == ListOfState[TEXT("VillageInTheTree")][0]) {
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

void AMyGameStateBase::FirstStateNulberOfKeyCheck() {
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