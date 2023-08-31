// Fill out your copyright notice in the Description page of Project Settings.

#include "Actors/Weapons/Weapon.h"
#include "Characters/EchoCharacter.h"

void AWeapon::Equip(USceneComponent* InParent, FName InSocketName)
{
	FAttachmentTransformRules TransformRules(EAttachmentRule::SnapToTarget, true);
	MyActorMesh->AttachToComponent(InParent, TransformRules, InSocketName);
}

void AWeapon::OnSphereBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Super::OnSphereBeginOverlap(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);
	UE_LOG(LogTemp, Warning, TEXT("AWEAPON CLASS BEGIN OVERLAP"));
	AEchoCharacter* EchoCharacter = Cast<AEchoCharacter>(OtherActor);
	
	if (EchoCharacter)
	{
		UE_LOG(LogTemp, Warning, TEXT("AWEAPON CLASS BEGIN OVERLAP inside"));

		FAttachmentTransformRules TransformRules(EAttachmentRule::SnapToTarget, true);
		MyActorMesh->AttachToComponent(EchoCharacter->GetMesh(), TransformRules, FName("RightHandSocket"));
	}
}

void AWeapon::OnSphereEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	Super::OnSphereEndOverlap(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex);
}
