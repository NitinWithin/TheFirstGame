// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "EchoCharacter.generated.h"

class UInputMappingContext;
class UInputAction;
class USpringArmComponent;
class UCameraComponent;
class UGroomComponent;

UCLASS()
class THEFIRSTGAME_API AEchoCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AEchoCharacter();

	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual void Jump() override;

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = Input)
	UInputMappingContext* EchoContext;

	UPROPERTY(EditAnywhere, Category = Input)
	UInputAction* MovementAction;
	
	UPROPERTY(EditAnywhere, Category = Input)
	UInputAction* LookAction;
		
	UPROPERTY(EditAnywhere, Category = Input)
	UInputAction* JumpAction;
	
	UPROPERTY(EditAnywhere, Category = Input)
	UInputAction* EquipAction;
	
	UPROPERTY(EditAnywhere, Category = Input)
	UInputAction* AttackAction;
	
	UPROPERTY(EditAnywhere, Category = Input)
	UInputAction* DodgeAction;

	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);
	void Equip();
	void Dodge();

	//virtual void Attack() override;

private:

	UPROPERTY(VisibleAnywhere)
	USpringArmComponent* SpringArmForCamera;

	UPROPERTY(VisibleAnywhere)
	UCameraComponent* ViewCamera;

	UPROPERTY(VisibleAnywhere, Category = Hair)
	UGroomComponent* Hair;
	
	UPROPERTY(VisibleAnywhere, Category = Hair)
	UGroomComponent* Eyebrows;
};
