// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Platforme.generated.h"

UCLASS()
class SEMAINFORMATIONCPP_API APlatforme : public AActor
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* TestVisualMesh;

public:	
	// Sets default values for this actor's properties
	APlatforme();

	float LerpAlpha = 0.0f;
	UPROPERTY(EditAnywhere)
	float LerpStep = 0.0f;
	UPROPERTY(EditAnywhere)
	TArray<FVector> Position;

	int32 CurrentIndex;
	int32 GoToIndex;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
