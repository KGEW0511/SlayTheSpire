// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerHUD.h"

#include "CardDrag.h"
#include "CardManager.h"
#include "CardWidget.h"
#include "Enemy.h"
#include "SlayPlayer.h"
#include "Kismet/GameplayStatics.h"

void UPlayerHUD::NativeConstruct()
{
	Super::NativeConstruct();

	CardWidget0 = Cast<UCardWidget>(GetWidgetFromName(TEXT("WBPCard0")));
	CardWidget1 = Cast<UCardWidget>(GetWidgetFromName(TEXT("WBPCard1")));
	CardWidget2 = Cast<UCardWidget>(GetWidgetFromName(TEXT("WBPCard2")));

	CardWidget0->CardIndex = 0;
	CardWidget1->CardIndex = 1;
	CardWidget2->CardIndex = 2;
}

bool UPlayerHUD::NativeOnDrop(const FGeometry& InGeometry, const FDragDropEvent& InDragDropEvent,
	UDragDropOperation* InOperation)
{
	Super::NativeOnDrop(InGeometry, InDragDropEvent, InOperation);

	auto* io = Cast<UCardDrag>(InOperation);
	
	io->WidgetReference->RemoveFromParent();

	CardIndex = io->CardIndex;

	FCardInfo cardInfo;
	FTimerHandle TimerHandle;
	GetWorld()->GetTimerManager().SetTimer(TimerHandle,
		[&]()
		{
			cardManager = Cast<ACardManager>(UGameplayStatics::GetActorOfClass(GetWorld(),ACardManager::StaticClass()));
			cardInfo = cardManager->GetCard(CardIndex);
			
			if (cardInfo.CardType == ECardType::Attack)
			{
				FHitResult hitResult;
	
				bool bHit = GetWorld()->GetFirstPlayerController()->GetHitResultUnderCursorByChannel
				(TraceTypeQuery1, true, hitResult);
	
				if (bHit) return;
				if (nullptr != Cast<AEnemy>(hitResult.GetActor()))
				{
					cardManager->targetEnemy = Cast<AEnemy>(hitResult.GetActor());
					cardManager->UseCard(CardIndex);
				}
			}
			else
			{
				cardManager->UseCard(CardIndex);
			}
		}
		,0.1f ,false);
	
	return false;
}
