// ©Justin Camden 2019, all rights reserved.


#include "HorusStandardGameMode.h"
#include "Arena/HorusArena.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"

void AHorusStandardGameMode::BeginPlay()
{
	Super::BeginPlay();

	// Get arena reference
	TArray<AActor*> Arenas;
	UGameplayStatics::GetAllActorsOfClass(this, AHorusArena::StaticClass(), Arenas);
	if (Arenas.Num() > 0)
	{
		Arena = Cast<AHorusArena>(Arenas[0]);
	}

	// Initialize the arena if appropriate
	if (Arena)
	{
		//Arena->InitializeArena();
	}
}
