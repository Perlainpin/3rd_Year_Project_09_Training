// Fill out your copyright notice in the Description page of Project Settings.


#include "Platforme.h"

// Sets default values
APlatforme::APlatforme()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    TestVisualMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
    TestVisualMesh->SetupAttachment(RootComponent);

    static ConstructorHelpers::FObjectFinder<UStaticMesh> TestCubeVisualAsset(TEXT("/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube"));

    if (TestCubeVisualAsset.Succeeded())
    {
        TestVisualMesh->SetStaticMesh(TestCubeVisualAsset.Object);
        TestVisualMesh->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
    }
}

// Called when the game starts or when spawned
void APlatforme::BeginPlay()
{
	Super::BeginPlay();
	
    CurrentIndex = 0;
    GoToIndex = CurrentIndex + 1;
}

// Called every frame
void APlatforme::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

    LerpAlpha += LerpStep * DeltaTime;

    SetActorLocation(FMath::Lerp(Position[CurrentIndex], Position[GoToIndex], LerpAlpha));
    if (LerpStep > 0 && LerpAlpha >= 1){
        LerpAlpha = 0;

        if (CurrentIndex == Position.Num() - 2) {
            CurrentIndex = Position.Num() - 1;
            GoToIndex = 0;
        }
        else {
            CurrentIndex = GoToIndex;
            GoToIndex = CurrentIndex + 1;
        }
    }

}

