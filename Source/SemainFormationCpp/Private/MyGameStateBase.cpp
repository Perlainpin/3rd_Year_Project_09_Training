// Fill out your copyright notice in the Description page of Project Settings.

#include "MyGameStateBase.h"

AMyGameStateBase::AMyGameStateBase() 
{

}

void AMyGameStateBase::BeginPlay()
{
	Super::BeginPlay();

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
	ActualLevel = ListOfLevel[0];
	ActualState = ListOfState[ActualLevel][0];
	FirstStateNumberOfKey = 0;
	FirstStateNeededNumberOfKey = 3;
};

void AMyGameStateBase::UpdateState() {
	FirstStateNumberOfKeyCheck();
	ChangeActualState();
	ChangeActualLevel();
}

void AMyGameStateBase::ChangeActualState() {
	if (StateIndex > ListOfState[ActualLevel].Num()) {
		LevelIndex++;
		StateIndex = 0;
	}
	ActualState = ListOfState[ActualLevel][StateIndex];
};

void AMyGameStateBase::ChangeActualLevel() {
	ActualLevel = ListOfLevel[LevelIndex];
}

void AMyGameStateBase::AddFirstSateKey(){
	if (ActualState == ListOfState[TEXT("EscapeTheOrkCamp")][0]) {
		FirstStateNumberOfKey++;
	};
};

int32 AMyGameStateBase::GetFirstStateKey() {
	return FirstStateNumberOfKey;
};

int32 AMyGameStateBase::GetFirstStateNeededKey() {
	return FirstStateNeededNumberOfKey;
};

FName AMyGameStateBase::GetActuaLevel() {
	return ActualLevel;
};

FName AMyGameStateBase::GetActualState() {
	return ActualState;
};

void AMyGameStateBase::FirstStateNumberOfKeyCheck() {
	if (ActualState == ListOfState[TEXT("EscapeTheOrkCamp")][0] && FirstStateNumberOfKey == FirstStateNeededNumberOfKey){
		StateIndex++;
	};
};

void AMyGameStateBase::TriggerStateChange() {
	StateIndex++;
}