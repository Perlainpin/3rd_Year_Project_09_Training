// Fill out your copyright notice in the Description page of Project Settings.


#include "MySemainFormationCppGameMode.h"
#include "MyGameStateBase.h"

AMySemainFormationCppGameMode::AMySemainFormationCppGameMode() {
	GameStateClass = AMyGameStateBase::StaticClass();
}

void AMySemainFormationCppGameMode::StartPlay() {
	StartPlayEvent();

	GetWorld()->GetAuthGameMode()->GetGameState<AMyGameStateBase>();

	Super::StartPlay();
}

void AMySemainFormationCppGameMode::StartPlayEvent() {

}