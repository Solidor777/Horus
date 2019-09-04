// ©Justin Camden 2019, all rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Horus/Arena/HorusArena.h"
#include "HorusArenaDataCreator.generated.h"

UCLASS()
class HORUSEDITOR_API AHorusArenaDataCreator : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AHorusArenaDataCreator(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

	/** The generated arena data. */
	FHorusArenaData ArenaData;

	/*
	* Function for updating the references to zones placed with the arena
	*/
	UFUNCTION(BlueprintCallable, Category = HorusArena)
		void UpdateZoneMappings();
};
