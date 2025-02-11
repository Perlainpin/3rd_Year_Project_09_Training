// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Bind.generated.h"

UCLASS(Abstract)
class SEMAINFORMATIONCPP_API UBind : public UUserWidget
{
	GENERATED_BODY()

public:
	void SetHealth(float CurrentHealth, float MaxHealth);
	void SetXP(float CurrentXP, float MaxXP);
	void SetLevel(FText CurrentLevel);
	void SetState(FText CurrentState);
	void SetTriSlider(float CurrentPercent);
	void SetRainSlider(float CurrentPercent);

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UProgressBar* HealthBar;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UProgressBar* XPBar;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UEditableText* LevelText;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UEditableText* StateText;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class URadialSlider* TriSlider;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class URadialSlider* RainSlider;
};
