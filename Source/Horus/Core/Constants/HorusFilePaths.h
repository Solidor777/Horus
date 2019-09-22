// ©Justin Camden 2019, all rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Runtime/Core/Public/Misc/Paths.h"
#include "HorusFilePaths.generated.h"

/**
 * Container for static const file paths and file names
 */
UCLASS()
class HORUS_API UHorusFilePaths : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	/** Localized path to the Arena Database. */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = HorusFilePaths)
	static FString ArenaDatabase();

	/** Localized path to the Arena Built Foles. */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = HorusFilePaths)
		static FString ArenasRoot();


	
};

FORCEINLINE FString UHorusFilePaths::ArenaDatabase()
{
	FString RetVal = FPaths::ProjectContentDir();
	RetVal += "Horus/BuiltFiles/Arenas/ArenaDatabase.adb";
	return RetVal;
}


FORCEINLINE FString UHorusFilePaths::ArenasRoot()
{
	FString RetVal = FPaths::ProjectContentDir();
	RetVal += "Horus/BuiltFiles/Arenas/";
	return RetVal;
}

