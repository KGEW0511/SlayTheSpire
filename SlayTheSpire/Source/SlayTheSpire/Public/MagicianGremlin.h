// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Enemy.h"
#include "MagicianGremlin.generated.h"

/**
 * 
 */
UCLASS()
class SLAYTHESPIRE_API AMagicianGremlin : public AEnemy
{
	GENERATED_BODY()

	virtual void BeginPlay() override;
public:
	UFUNCTION()
	void Attack(int32 index);

	UPROPERTY(EditAnywhere)
	TArray<int32> AttackPartern;

	UPROPERTY(EditAnywhere)
	int32 TurnIndex;

	void Charge();

	void MagicAttack();

	UFUNCTION()
	void StartTurn();
};
