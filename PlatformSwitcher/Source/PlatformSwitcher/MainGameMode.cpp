// Fill out your copyright notice in the Description page of Project Settings.

#include "MainGameMode.h"
#include <Kismet/GameplayStatics.h>
#include <GameFramework/Character.h>

void AMainGameMode::BeginPlay()
{
	Super::BeginPlay();

	GetWorld()->GetFirstPlayerController()->InputComponent
		->BindAction("Switch", IE_Pressed, this, &AMainGameMode::OnSwitch);

	Switched = false;
}

void AMainGameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AMainGameMode::OnSwitch()
{
	if (Switched) {
		FVector NewLocation = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0)->GetActorLocation();
		NewLocation.X = 1200.f;
		UGameplayStatics::GetPlayerCharacter(GetWorld(), 0)->SetActorLocation(NewLocation);
	}
	else {
		FVector NewLocation = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0)->GetActorLocation();
		NewLocation.X = 370.f;
		UGameplayStatics::GetPlayerCharacter(GetWorld(), 0)->SetActorLocation(NewLocation);
	}
	Switched = !Switched;
}

void AMainGameMode::OnGameOver(bool win)
{
	UGameplayStatics::SetGamePaused(GetWorld(), true);
}
