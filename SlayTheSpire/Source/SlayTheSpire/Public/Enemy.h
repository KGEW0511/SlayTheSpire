// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Enemy.generated.h"

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
	UFUNCTION(BlueprintCallable)
	void TakeDamage(float value);

	void Death();
	
	UFUNCTION()
	void TurnOver();
	
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
};
