// ©Justin Camden 2019, all rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "HorusSpellCard.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "HorusCardSubsystem.generated.h"


/**
 * Subsystem for managing card data, including loading, unloading, retrieving, and updating data about cards.
 */
UCLASS()
class HORUS_API UHorusCardSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	/** Function for loading a properly formatted CSV table to a map of names to SpellCardData structs. */
	UFUNCTION(BlueprintCallable, Category = HorusCardSubsystem)
	const bool LoadSpellCardMapFromCSV(TMap<FName, FHorusSpellCardData>& OutMap, const FString& Filename);
	
};
