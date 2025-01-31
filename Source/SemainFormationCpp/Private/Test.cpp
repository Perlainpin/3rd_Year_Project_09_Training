// Fill out your copyright notice in the Description page of Project Settings.


#include "Test.h"

// Sets default values
ATest::ATest()
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
        TestVisualMesh->SetCollisionProfileName(TEXT("OverlapALL"));
    }
    Delegate.BindUFunction(this, "OnActorBump");
}

// Called when the game starts or when spawned
void ATest::BeginPlay()
{
    Super::BeginPlay();
    IsPress = false;
}

// Called every frame
void ATest::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    TestVisualMesh->OnComponentBeginOverlap.AddUnique(Delegate);

    
    if (IsPress) {
        Door->LerpAlpha += Door->LerpStep * DeltaTime;

        Door->SetActorLocation(FMath::Lerp(Door->WorldStartLocation, Door->WorldEndLocation, Door->LerpAlpha));
        if (Door->LerpStep > 0 && Door->LerpAlpha >= 1 || Door->LerpStep < 0 && Door->LerpAlpha <= 0) {
            Door->LerpStep *= -1;
            IsPress = false;
        }
    }
}

void ATest::OnActorBump(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit)
{
    IsPress = true;
}

