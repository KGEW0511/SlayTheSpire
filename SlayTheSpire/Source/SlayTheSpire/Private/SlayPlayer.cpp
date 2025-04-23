// Fill out your copyright notice in the Description page of Project Settings.


#include "SlayTheSpire/Public/SlayPlayer.h"

// Sets default values
ASlayPlayer::ASlayPlayer()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASlayPlayer::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASlayPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

