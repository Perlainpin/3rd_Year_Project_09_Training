// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActorTest.generated.h"

UCLASS()
class SEMAINFORMATIONCPP_API AMyActorTest : public AActor
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* VisualMesh;

public:
	// Sets default values for this actor's properties
	AMyActorTest();

	UPROPERTY(EditAnywhere)
	FVector WorldStartLocation;
	UPROPERTY(EditAnywhere)
	FVector WorldEndLocation;
	float LerpAlpha = 0.0f;
	UPROPERTY(EditAnywhere)
	float LerpStep = 0.0f;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
