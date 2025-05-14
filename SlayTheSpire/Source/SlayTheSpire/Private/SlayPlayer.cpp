// Fill out your copyright notice in the Description page of Project Settings.


#include "SlayTheSpire/Public/SlayPlayer.h"

#include "CardManager.h"
#include "Enemy.h"
#include "PlayerHpBar.h"
#include "Components/WidgetComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ASlayPlayer::ASlayPlayer()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	SetRootComponent(MeshComp);
	
	hpBar = CreateDefaultSubobject<UWidgetComponent>(TEXT("hpBar"));
	hpBar->SetupAttachment(MeshComp);

	static ConstructorHelpers::FClassFinder<UUserWidget> UW
	(TEXT("/Script/UMGEditor.WidgetBlueprint'/Game/UI/WBP_PlayerHpBar.WBP_PlayerHpBar_C'"));
	
	if (UW.Succeeded())
	{
		hpBar->SetWidgetClass(UW.Class);
		hpBar->SetRelativeLocation(FVector(0.0f, 0.0f, 100.0f));
		hpBar->SetWidgetSpace(EWidgetSpace::Screen);
		hpBar->SetDrawSize(FVector2D(200.f, 50.f));
	}
}

// Called when the game starts or when spawned
void ASlayPlayer::BeginPlay()
{
	Super::BeginPlay();
	
	Cast<UPlayerHpBar>(hpBar->GetWidget())->player = this;
}

// Called every frame
void ASlayPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASlayPlayer::Attack(int index)
{
	switch (index)
	{
	case 1001:
		targetEnemy = cardManager->targetEnemy;
		targetEnemy->OnTakeDamage(1);
		break;
	case 1002:
		CurHp += 1;
		break;
	}
}

void ASlayPlayer::Damage(int value)
{
	if (bIsDebuff)
	{
		value *= 1.5f;
		value = floor(value + 0.5f);
	}

	CurHp -= value;

	if (CurHp <= 0)
	{
		CurHp = 0;
		
	}
}

