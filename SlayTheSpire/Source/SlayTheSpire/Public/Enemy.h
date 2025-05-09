// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Enemy.generated.h"

class ASlayPlayer;

UCLASS()
class SLAYTHESPIRE_API AEnemy : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnemy();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	UFUNCTION()
	void OnTakeDamage(float value);

	void Death();
	
	UFUNCTION()
	void TurnOver();
	
	UFUNCTION()
	void Attack(ASlayPlayer* player);
	
	UPROPERTY(EditAnywhere)
	float CurHp;
	UPROPERTY(EditAnywhere)
	float MaxHp;
	
	bool bIsDebuff;
	
	int32 DebuffDurationTurn;

	UPROPERTY(EditAnywhere)
	class UStaticMeshComponent* MeshComp;

	UPROPERTY(EditAnywhere)
	class UWidgetComponent* hpBar;

	UPROPERTY(EditAnywhere)
	TArray<int32> AttackPartern;

	UPROPERTY(EditAnywhere)
	int32 TurnIndex;

	void Charge();

	void MagicAttack(ASlayPlayer* player);
};
