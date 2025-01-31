// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActorTest.h"
#include "Test.generated.h"

UCLASS()
class SEMAINFORMATIONCPP_API ATest : public AActor
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	AMyActorTest* Door;


	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* TestVisualMesh;

	FScriptDelegate Delegate;

	bool IsPress;

	UFUNCTION()
	void OnActorBump(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit);
	
public:	
	// Sets default values for this actor's properties
	ATest();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
