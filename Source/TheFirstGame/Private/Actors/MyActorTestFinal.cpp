// Fill out your copyright notice in the Description page of Project Settings.

#include "Actors/MyActorTestFinal.h"
#include "Characters/EchoCharacter.h"
#include "TheFirstGame/DebugMacros.h"
#include "Components/SphereComponent.h"

// Sets default values
AMyActorTestFinal::AMyActorTestFinal()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MyActorMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MyActorMeshComponent"));
	RootComponent = MyActorMesh;

	CollisionSphere = CreateDefaultSubobject<USphereComponent>(TEXT("CollisionSphere"));
	CollisionSphere->SetupAttachment(GetRootComponent());
}

// Called when the game starts or when spawned
void AMyActorTestFinal::BeginPlay()
{
	Super::BeginPlay();

	//SetActorLocation(FVector(0.f, 0.f, 50.f));
	//SetActorRotation(FRotator(0.f, 45.f, 0.f));

	// FVector Forward = GetActorForwardVector();

	//DRAW_CollisionSphere(Location);
	//DRAW_LINE(Location, Location + Forward * 100.f);

	//DRAW_POINT(Location + Forward * 100.f);

	UWorld* World = GetWorld();
	FVector Location = GetActorLocation();

	CollisionSphere->OnComponentBeginOverlap.AddDynamic(this, &AMyActorTestFinal::OnSphereBeginOverlap);
	CollisionSphere->OnComponentEndOverlap.AddDynamic(this, &AMyActorTestFinal::OnSphereEndOverlap);
}

float AMyActorTestFinal::TransformedSin()
{
	return Amplitude * FMath::Sin(RunningTime * TimeConstant);
}

float AMyActorTestFinal::TransformedCos()
{
	return Amplitude * FMath::Cos(RunningTime * TimeConstant);
}


void AMyActorTestFinal::OnSphereBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	AEchoCharacter* EchoCharacter = Cast<AEchoCharacter>(OtherActor);
	if (EchoCharacter)
	{
		EchoCharacter->SetOverlappingItem(this);
	}
}

void AMyActorTestFinal::OnSphereEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	AEchoCharacter* EchoCharacter = Cast<AEchoCharacter>(OtherActor);
	if (EchoCharacter)
	{
		EchoCharacter->SetOverlappingItem(nullptr);
	}
}

// Called every frame
void AMyActorTestFinal::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	RunningTime += DeltaTime;

	//Code for hovering item up and down
	//AddActorWorldOffset(FVector(0.f, 0.f, TransformedSin()));
	// Code for rotating item
	//AddActorWorldRotation(FRotator(0.f, 0.f, TransformedCos()));
}
