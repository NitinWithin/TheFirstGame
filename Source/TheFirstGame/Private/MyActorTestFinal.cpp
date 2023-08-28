// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/MyActorTestFinal.h"
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
	const FString OtherActorName = OtherActor->GetName();

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(1, 30.f, FColor::Red, OtherActorName);

		UE_LOG(LogTemp, Warning, TEXT("PRINTING TO OUTPUT"));
	}
}

void AMyActorTestFinal::OnSphereEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	const FString OtherActorName = OtherActor->GetName();

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(1, 30.f, FColor::Red, OtherActorName);
		UE_LOG(LogTemp, Warning, TEXT("PRINTING TO OUTPUT END OVERLAP"));
	}
}

// Called every frame
void AMyActorTestFinal::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	RunningTime += DeltaTime;

	float DeltaZ = Amplitude * FMath::Sin(RunningTime * 5.f);
	float RoatateZ = Amplitude * FMath::Cos(RunningTime * 0.5f);

	AddActorWorldOffset(FVector(0.f, 0.f, DeltaZ));
	//AddActorWorldRotation(FRotator(0.f, 0.f, RoatateZ));
	
}
