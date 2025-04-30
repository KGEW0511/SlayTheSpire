// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "EnemyHpBar.generated.h"

/**
 * 
 */
UCLASS()
class SLAYTHESPIRE_API UEnemyHpBar : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void NativeConstruct() override;

	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class AEnemy* enemy;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UProgressBar* hpBar;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UTextBlock* curHpText;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UTextBlock* maxHpText;
};
