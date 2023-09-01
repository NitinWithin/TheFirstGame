#pragma once


// Using "enum class" makes this is a scoped enum, to use this enum, we would need to use fully qualified name.
// Eg: ECharacterState State = ECharacterState::Unequipped
// ECS - ECharacterState
UENUM(BlueprintType)
enum class ECharacterState : uint8
{
	ECS_Unequipped UMETA(DisplayName = "Unequipped"),
	ECS_EquippedOneHandWeapon UMETA(DisplayName = "Equipped One-Hand Weapon"),
	ECS_EquippedTwoHandWeapon UMETA(DisplayName = "Equipped Two-Hand Weapon")
};