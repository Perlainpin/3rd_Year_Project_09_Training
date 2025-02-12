// Fill out your copyright notice in the Description page of Project Settings.

#include "Bind.h"
#include "Components/ProgressBar.h"
#include "Components/TextBlock.h"
#include "Components/RadialSlider.h"


void UBind::SetHealth(float CurrentHealth, float MaxHealth) {
	if (HealthBar) {
		HealthBar->SetPercent(CurrentHealth / MaxHealth);
	}
}
void UBind::SetXP(float CurrentXP, float MaxXP) {
	if (XPBar) {
		XPBar->SetPercent(CurrentXP / MaxXP);
	}
}

void UBind::SetLevel(FText CurrentLevel) {
	if (LevelText) {
		UE_LOG(LogTemp, Warning, TEXT("Update UI level text"));
		LevelText->SetText(CurrentLevel);
	}
}

void UBind::SetState(FText CurrentState) {
	if (StateText) {
		StateText->SetText(CurrentState);
	}
}

void UBind::SetTriSlider(float CurrentPercent) {
	if (TriSlider) {
		TriSlider->SetValue(CurrentPercent);
	}
}

void UBind::SetRainSlider(float CurrentPercent) {
	if (RainSlider) {
		RainSlider->SetValue(CurrentPercent);
	}
}