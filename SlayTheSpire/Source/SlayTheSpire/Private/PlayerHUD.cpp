// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerHUD.h"

#include "CardDrag.h"
#include "CardManager.h"
#include "CardWidget.h"
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

	UE_LOG(LogTemp, Warning, TEXT("Droped"));
	
	CardIndex = io->CardIndex;
	io->WidgetReference->RemoveFromParent();

	FTimerHandle TimerHandle;
	GetWorld()->GetTimerManager().SetTimer(TimerHandle,
		[&]()
		{
			auto* CardManager = Cast<ACardManager>(UGameplayStatics::GetActorOfClass(GetWorld(),ACardManager::StaticClass()));

			CardManager->GetCard(CardIndex);
		}
		,0.1f ,false);
	
	
	
	return true;
}
