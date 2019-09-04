// ©Justin Camden 2019, all rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Arena/ArenaZoneS/HorusArenaZone.h"
#include "HorusUtilityLibrary.generated.h"


template <typename T>
FORCEINLINE T* GetRandomEntryFromProbabilityPackage(TMap<T, uint8> EntriesToRelativeProbability)
{
	if (EntriesToRelativeProbability.Num() > 0)
	{
		int32 ChanceRoll = 0;
		for (auto& CurrentEntry : EntriesToRelativeProbability)
		{
			ChanceRoll += CurrentEntry.Value;
		}
		ChanceRoll = FMath::RandRange(0, ChanceRoll - 1);
		int32 CurrentChancesChecked = 0;
		for (auto& CurrentEntry : EntriesToRelativeProbability)
		{
			if (CurrentEntry.Value + CurrentChancesChecked > ChanceRoll)
			{
				return &CurrentEntry.Key;
			}
			else
			{
				CurrentChancesChecked += CurrentEntry.Value;
			}
		}
	}

	return nullptr;
}

/**
 * Helper functions and types for misc functionality used by multiple game segments.
 */
UCLASS()
class HORUS_API UHorusUtilityLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	/** Gets a random Arena Zone class from a map of zone classes to relative probability. */
	UFUNCTION(BlueprintCallable, Category = HorusUtilityLibrary)
		TSubclassOf<AHorusArenaZone> GetArenaZoneFromProbabilityPackage(TMap<TSubclassOf<AHorusArenaZone>, uint8> EntriesToRelativeProbability) { return (EntriesToRelativeProbability.Num() > 0 ? *GetRandomEntryFromProbabilityPackage(EntriesToRelativeProbability) : AHorusArenaZone::StaticClass()); }
};
