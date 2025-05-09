// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyHpBar.h"

#include "CardManager.h"
#include "Enemy.h"
#include "Components/ProgressBar.h"
#include "Components/TextBlock.h"
#include "Kismet/GameplayStatics.h"

void UEnemyHpBar::NativeConstruct()
{
	Super::NativeConstruct();

	hpBar = Cast<UProgressBar>(GetWidgetFromName(TEXT("EnemyHpBar")));
	curHpText = Cast<UTextBlock>(GetWidgetFromName(TEXT("EnemyCurHpText")));
	maxHpText = Cast<UTextBlock>(GetWidgetFromName(TEXT("EnemyMaxHpText")));
}

void UEnemyHpBar::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);

	hpBar->SetPercent(enemy->CurHp/enemy->MaxHp);
	
	curHpText->SetText(FText::AsNumber(enemy->CurHp));
	maxHpText->SetText(FText::AsNumber(enemy->MaxHp));
	
}
