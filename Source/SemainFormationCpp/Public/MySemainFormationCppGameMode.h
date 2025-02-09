// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../SemainFormationCppGameMode.h"
#include "MySemainFormationCppGameMode.generated.h"

UCLASS()

class SEMAINFORMATIONCPP_API AMySemainFormationCppGameMode : public ASemainFormationCppGameMode
{
	GENERATED_BODY()
	
public:
	AMySemainFormationCppGameMode();
	virtual ~AMySemainFormationCppGameMode() = default;

	virtual void StartPlay();

	void StartPlayEvent();
};
