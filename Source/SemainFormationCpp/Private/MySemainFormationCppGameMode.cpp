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

    if (MainMenuWidgetClass)
    {
        MainMenuWidget = CreateWidget<UUserWidget>(GetWorld(), MainMenuWidgetClass);

        if (MainMenuWidget)
        {
            MainMenuWidget->AddToViewport();
        }
    }
}

void AMySemainFormationCppGameMode::StartPlayEvent() {

}