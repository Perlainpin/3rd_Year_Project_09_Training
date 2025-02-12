// Fill out your copyright notice in the Description page of Project Settings.

#include "MySemainFormationCppGameMode.h"
#include "MyGameStateBase.h"
#include "Bind.h"

AMySemainFormationCppGameMode::AMySemainFormationCppGameMode() {
    GameStateClass = AMyGameStateBase::StaticClass();
    MainMenuWidgetClass = nullptr;
    MainMenuWidget = nullptr;
}

void AMySemainFormationCppGameMode::StartPlay() {
    GetWorld()->GetAuthGameMode()->GetGameState<AMyGameStateBase>();

	Super::StartPlay();

    if (MainMenuWidgetClass)
    {
        MainMenuWidget = CreateWidget<UBind>(GetWorld(), MainMenuWidgetClass);

        if (MainMenuWidget)
        {
            MainMenuWidget->AddToViewport();
            MainMenuWidget->SetLevel(FText::FromName(GetWorld()->GetAuthGameMode()->GetGameState<AMyGameStateBase>()->GetActuaLevel()));
            MainMenuWidget->SetState(FText::FromName(GetWorld()->GetAuthGameMode()->GetGameState<AMyGameStateBase>()->GetActualState()));
            MainMenuWidget->SetHealth(100, 100);
        }
    }
}

void AMySemainFormationCppGameMode::ArrowsRainSlideRecharge(float deltatime) {
    if (MainMenuWidget)
    {
        MainMenuWidget->SetTriSlider(deltatime);
    }
}

void AMySemainFormationCppGameMode::TriSpellSlideRecharge(float deltatime) {
    if (MainMenuWidget)
    {
        MainMenuWidget->SetTriSlider(deltatime);
    }0
}