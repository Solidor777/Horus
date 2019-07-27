// ©Justin Camden 2019, all rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Core/HorusGameModeBase.h"
#include "HorusStandardGameMode.generated.h"

class AHorusArena;

/**
 * 
 */
UCLASS()
class HORUS_API AHorusStandardGameMode : public AHorusGameModeBase
{
	GENERATED_BODY()

public:
	/** Returns the reference to the primary arena. */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = HorusStandardGameMode)
	AHorusArena* GetArena() const { return Arena; }

protected:
	virtual void BeginPlay() override;

private:

	/** Reference to the primary arena. */
	AHorusArena* Arena;
};
