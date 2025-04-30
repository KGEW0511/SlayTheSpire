// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SlayPlayer.generated.h"

UCLASS()
class SLAYTHESPIRE_API ASlayPlayer : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASlayPlayer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	float CurHp;

	UPROPERTY(EditAnywhere)
	float MaxHp;

	UPROPERTY(EditAnywhere)
	float CurCost;

	UPROPERTY(EditAnywhere)
	float MaxCost;

	UPROPERTY(EditAnywhere)
	bool bIsBuff;

	UPROPERTY(EditAnywhere)
	int BuffDurationTurn;

	UPROPERTY(EditAnywhere)
	bool bIsDebuff;

	UPROPERTY(EditAnywhere)
	int DebuffDurationTurn;
	
	UFUNCTION(BlueprintCallable)
	void Attack(int index);

	UFUNCTION()
	void Damage(int value);

	UPROPERTY(EditAnywhere)
	class AEnemy* targetEnemy;

	UPROPERTY(EditAnywhere)
	class ACardManager* cardManager;

	UPROPERTY(EditAnywhere)
	class UWidgetComponent* hpBar;
	
	UPROPERTY(EditAnywhere)
	class UUserWidget* HUD;

	UPROPERTY(EditAnywhere)
	class UStaticMeshComponent* MeshComp;
};
