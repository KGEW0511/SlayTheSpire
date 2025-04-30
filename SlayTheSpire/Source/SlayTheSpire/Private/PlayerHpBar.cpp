// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerHpBar.h"

#include "SlayPlayer.h"
#include "Components/ProgressBar.h"
#include "Components/TextBlock.h"
#include "Kismet/GameplayStatics.h"

void UPlayerHpBar::NativeConstruct()
{
	Super::NativeConstruct();

	hpBar = Cast<UProgressBar>(GetWidgetFromName(TEXT("PlayerHpBar")));
	curHpText = Cast<UTextBlock>(GetWidgetFromName(TEXT("PlayerCurHpText")));
	maxHpText = Cast<UTextBlock>(GetWidgetFromName(TEXT("PlayerMaxHpText")));
}

void UPlayerHpBar::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);
	
	hpBar->SetPercent(player->CurHp/player->MaxHp);
	
	curHpText->SetText(FText::AsNumber(player->CurHp));
	maxHpText->SetText(FText::AsNumber(player->MaxHp));
}
