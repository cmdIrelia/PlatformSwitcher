// Fill out your copyright notice in the Description page of Project Settings.

#include "OrbController.h"

#include <Components/BoxComponent.h>
#include <Components/PrimitiveComponent.h>
#include "Kismet/GameplayStatics.h"
#include "MainGameMode.h"
#include "GameFramework/Character.h"

// Sets default values
AOrbController::AOrbController()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootBox = CreateDefaultSubobject<UBoxComponent>(TEXT("Root"));
	RootBox->SetGenerateOverlapEvents(true);
	RootBox->OnComponentBeginOverlap.AddDynamic(this, &AOrbController::OnOverlap);
	SetRootComponent(RootBox);

}

// Called when the game starts or when spawned
void AOrbController::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AOrbController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AOrbController::OnOverlap(UPrimitiveComponent *OverlapComponent,
	AActor *OtherActor,
	UPrimitiveComponent *OtherComponent,
	int32 OtherBodyIndex,
	bool bFromSweep,
	const FHitResult &SweepResult)
{
	if (OtherActor == UGameplayStatics::GetPlayerCharacter(GetWorld(), 0)){ 
		
		float time = GetWorld()->GetTimeSeconds();
		UE_LOG(LogTemp, Warning, TEXT("%f: Player Overlap on %s. Game Win."), time, *GetName());

		//ÓÎÏ·½áÊø
		((AMainGameMode*)GetWorld()->GetAuthGameMode())->OnGameOver(true);

		//UGameplayStatics::SetGamePaused(GetWorld(), true);
	}
}
