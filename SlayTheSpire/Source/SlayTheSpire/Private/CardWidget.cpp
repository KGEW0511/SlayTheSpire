// Fill out your copyright notice in the Description page of Project Settings.


#include "CardWidget.h"

#include "CardDrag.h"
#include "CardManager.h"
#include "DragWidget.h"
#include "Blueprint/SlateBlueprintLibrary.h"
#include "Blueprint/WidgetBlueprintLibrary.h"
#include "Components/Image.h"
#include "Components/SizeBox.h"
#include "Components/TextBlock.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetInputLibrary.h"

void UCardWidget::NativeConstruct()
{
	Super::NativeConstruct();

	CardNameSizeBox = Cast<USizeBox>(GetWidgetFromName(TEXT("CardNameSizeBox")));
	CardNameText = Cast<UTextBlock>(GetWidgetFromName(TEXT("CardNameText")));
	ImageSizeBox = Cast<USizeBox>(GetWidgetFromName(TEXT("CardImageSizeBox")));
	CardImage = Cast<UImage>(GetWidgetFromName(TEXT("CardImage")));

	FTimerHandle TimerHandle;
	GetWorld()->GetTimerManager().SetTimer(TimerHandle,
		[&]()
		{
			auto* CardManager = Cast<ACardManager>(UGameplayStatics::GetActorOfClass(GetWorld(),ACardManager::StaticClass()));
			CurCardTexture = CardManager->GetCard(CardIndex).CardImage;
			CardImage->SetBrush(UWidgetBlueprintLibrary::MakeBrushFromTexture(CurCardTexture, 200.f, 200.f));
		}
		,0.1f ,false);
}

FReply UCardWidget::NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
	Super::NativeOnMouseButtonDown(InGeometry, InMouseEvent);
	
	DragOffset = USlateBlueprintLibrary::AbsoluteToLocal
	(InGeometry, UKismetInputLibrary::PointerEvent_GetScreenSpacePosition(InMouseEvent));
	
	return UWidgetBlueprintLibrary::DetectDragIfPressed(InMouseEvent, this, EKeys::LeftMouseButton).NativeReply;
}

void UCardWidget::NativeOnDragDetected(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent,
	UDragDropOperation*& OutOperation)
{
	Super::NativeOnDragDetected(InGeometry, InMouseEvent, OutOperation);

	auto* image = Cast<UTexture2D>(CardImage->GetBrush().GetResourceObject());
	
	DragWidget = CreateWidget<UDragWidget>(this,CardWidgetClass);
	DragWidget->AddToViewport();
	DragWidget->CardAfterImage->SetBrush(UWidgetBlueprintLibrary::MakeBrushFromTexture(image, 200.f, 200.f));
	
	CardDrag = NewObject<UCardDrag>();
	CardDrag->DefaultDragVisual = DragWidget;
	CardDrag->DragOffset = DragOffset;
	CardDrag->CardIndex = CardIndex;
}
