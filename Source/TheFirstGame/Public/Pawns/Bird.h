// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "InputActionValue.h"


#include "Bird.generated.h"

// Forward declaring classes
class UCapsuleComponent;
class USkeletalMesh;
class UInputMappingContext;
class UInputAction;
class USpringArmComponent;
class UCameraComponent;

UCLASS()
class THEFIRSTGAME_API ABird : public APawn
{
	GENERATED_BODY()
	
public:
	ABird();

	virtual void Tick(float DeltaTime) override;
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	void MoveForward(float Value);

	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category =  Input)
	UInputMappingContext* BirdMappingContext;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputAction* MoveAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputAction* LookAction;

	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);

private:
	UPROPERTY(VisibleAnywhere)
		UCapsuleComponent* Capsule;
	
	UPROPERTY(VisibleAnywhere)
		USkeletalMeshComponent* BirdMesh;

	UPROPERTY(VisibleAnywhere)
		USpringArmComponent* SpringArmForCamera;

	UPROPERTY(VisibleAnywhere)
		UCameraComponent* ViewCamera;

};
  