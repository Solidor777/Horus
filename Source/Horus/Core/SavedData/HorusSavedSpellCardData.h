// ©Justin Camden 2019, all rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "Cards/HorusSpellCard.h"
#include "HorusSavedSpellCardData.generated.h"

/**
 * Class for saving the necessary data for spell cards.
 */
UCLASS()
class HORUS_API UHorusSavedSpellCardData : public USaveGame
{
	GENERATED_BODY()

public:
	/*
	* List of spell card data contained in this file.
	*/
	UPROPERTY(BlueprintReadWrite, Category = HorusSavedSpellCardData)
		TMap<FName, FHorusSpellCardData> Cards;


};
