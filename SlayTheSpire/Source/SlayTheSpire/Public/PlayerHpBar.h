// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PlayerHpBar.generated.h"

/**
 * 
 */
UCLASS()
class SLAYTHESPIRE_API UPlayerHpBar : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void NativeConstruct() override;

	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class ASlayPlayer* player;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UProgressBar* hpBar;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UTextBlock* curHpText;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UTextBlock* maxHpText;
};
