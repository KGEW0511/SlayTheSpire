// Fill out your copyright notice in the Description page of Project Settings.


#include "DragWidget.h"

#include "CardWidget.h"
#include "Components/Image.h"
#include "Components/SizeBox.h"
#include "Kismet/KismetMathLibrary.h"

void UDragWidget::NativeConstruct()
{
	Super::NativeConstruct();

	WidgetSize->SetWidthOverride(200.f);
	WidgetSize->SetHeightOverride(200.f);
}
