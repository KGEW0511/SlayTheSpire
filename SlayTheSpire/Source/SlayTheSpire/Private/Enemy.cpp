// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy.h"

#include "EnemyHpBar.h"
#include "Components/WidgetComponent.h"

// Sets default values
AEnemy::AEnemy()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	SetRootComponent(MeshComp);
	
	hpBar = CreateDefaultSubobject<UWidgetComponent>(TEXT("hpBar"));
	hpBar->SetupAttachment(MeshComp);

	static ConstructorHelpers::FClassFinder<UUserWidget> UW
	(TEXT("/Script/UMGEditor.WidgetBlueprint'/Game/UI/WBP_EnemyHpBar.WBP_EnemyHpBar_C'"));
	
	if (UW.Succeeded())
	{
		hpBar->SetWidgetClass(UW.Class);
		hpBar->SetRelativeLocation(FVector(0.0f, 0.0f, 100.0f));
		hpBar->SetWidgetSpace(EWidgetSpace::Screen);
		hpBar->SetDrawSize(FVector2D(200.f, 50.f));
	}
}

// Called when the game starts or when spawned
void AEnemy::BeginPlay()
{
	Super::BeginPlay();

	Cast<UEnemyHpBar>(hpBar->GetWidget())->enemy = this;
}

// Called every frame
void AEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AEnemy::TakeDamage(float value)
{
	if (true == bIsDebuff)
	{
		value *= 1.5f;
		value = floor(value + 0.5f);
	}

	CurHp -= value;
	
	if (CurHp <= 0)
	{
		CurHp = 0;
		Death();
	}
	UE_LOG(LogTemp, Warning, TEXT("%f"), CurHp);
}

void AEnemy::Death()
{
	UE_LOG(LogTemp, Warning, TEXT("%f"), CurHp);
	
	this->Destroy();
}

void AEnemy::TurnOver()
{
	if (bIsDebuff)
	{
		DebuffDurationTurn -= 0;
		if (DebuffDurationTurn <= 0) bIsDebuff = false;
	}
}

