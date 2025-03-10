// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../SemainFormationCppGameMode.h"
#include "Blueprint/UserWidget.h"
#include "MySemainFormationCppGameMode.generated.h"

UCLASS()

class SEMAINFORMATIONCPP_API AMySemainFormationCppGameMode : public ASemainFormationCppGameMode
{
	GENERATED_BODY()
	
public:
	AMySemainFormationCppGameMode();
	virtual ~AMySemainFormationCppGameMode() = default;

	virtual void StartPlay();

	void ArrowsRainSlideRecharge(float deltatime);

	void TriSpellSlideRecharge(float deltatime);

protected:
	// Classe du Widget (modifiable dans l��diteur)
	UPROPERTY(EditDefaultsOnly, Category = "UI")
	TSubclassOf<class UBind> MainMenuWidgetClass;

private:
	UPROPERTY()
	UBind* MainMenuWidget;
};
