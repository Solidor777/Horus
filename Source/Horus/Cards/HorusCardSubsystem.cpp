// ©Justin Camden 2019, all rights reserved.


#include "HorusCardSubsystem.h"
#include "Runtime/Core/Public/Misc/FileHelper.h"

// Log categories
DEFINE_LOG_CATEGORY_STATIC(HorusCardSubsystem, All, All);

const bool UHorusCardSubsystem::LoadSpellCardMapFromCSV(TMap<FName, FHorusSpellCardData>& OutMap, const FString& Filename)
{
    // Load the file into lines
    TArray<FString> Rows;

    if (!FFileHelper::LoadFileToStringArray(Rows, *Filename))
    {
        UE_LOG(HorusCardSubsystem, Display, TEXT("HorusCardSubsystem: ERROR loading %s into SpellCardMap: File not found!"), *Filename);
        return false;
    }

    // Idx for debugging and checking success
    int32 DebugIdx = 0;

    // For each row
    for (FString& CurrRow : Rows)
    {
        // Parse file into the struct and set accordingly
        // Get the name from the first argument
        FString Left;
        FString Right;
        CurrRow.Split(TEXT(","), &Left, &Right);
        if (Left.Len() <= 0)
        {
            UE_LOG(HorusCardSubsystem, Display, TEXT("ERROR loading %s into SpellCardMap: Row %d Name is corrupted!"), *Filename, DebugIdx);
            return false;
        }
        FName CurrCardName = FName(*Left);

        // Get the mana cost from the next argument
        CurrRow = Right;
        CurrRow.Split(TEXT(","), &Left, &Right);   
        if (Left.Len() <= 0)
        {
            UE_LOG(HorusCardSubsystem, Display, TEXT("ERROR loading %s into SpellCardMap: Row %d Mana Cost is corrupted!"), *Filename, DebugIdx);
            return false;
        }
        FHorusSpellCardData CurrCardData;
        CurrCardData.ManaCost = FCString::Atoi(*Left);

        // Get the face material from the next argument
        CurrRow = Right;
        CurrRow.Split(TEXT(","), &Left, &Right);
        if (Left.Len() <= 0)
        {
            UE_LOG(HorusCardSubsystem, Display, TEXT("ERROR loading %s into SpellCardMap: Row %d Face Material is corrupted!"), *Filename, DebugIdx);
            return false;
        }
        CurrCardData.FaceMaterial = TSoftObjectPtr<UMaterialInstance>(FSoftObjectPath(Left));

        // Get the array of ints from the next argument
        // TODO

        // Get the array of names from the next argument
        // TODO

        // Add the card data to the out list
        OutMap.Add(CurrCardName, CurrCardData);
        DebugIdx++;
    }

    if (DebugIdx <=0 )
    {
        UE_LOG(HorusCardSubsystem, Display, TEXT("Warning loading file %s into SpellCardMap: No valid rows."), *Filename);
        return false;
    }

    return true;
}