// ©Justin Camden 2019, all rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "HorusFileHelperLibrary.generated.h"

/**
 * Library of functions to assist with file management
 */

UCLASS()
class HORUS_API UHorusFileHelperLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	/**
	* Returns the content directory of the current game by looking at FApp::GetProjectName().
	*
	* @return content directory
	 */
	static FString ProjectContentDir();
	
	/**
	 * Returns the saved directory of the current game by looking at FApp::GetProjectName().
	 *
	* @return saved directory
	 */
	static FString ProjectSavedDir();

	/*
	* Hashes the specified file contents and returns the result as a hexadecimal string. 
	* Returns INVALID HASH if not valid.
	*/
	UFUNCTION(BlueprintCallable, Category = HorusFileHelperLibrary)
	static bool HashFileToHexString(const FString& Filename, FString& OutHexString);

	/*
	* Decompresses an array of bytes
	*/
	UFUNCTION(BlueprintCallable, Category = HorusFileHelperLibrary)
	static bool DecompressBytes(const TArray<uint8>& CompressedBytes, TArray<uint8>& OutDecompressedBytes);

	/*
	* Converts an array of Bytes to an array of Strings.
	*/
	UFUNCTION(BlueprintCallable, Category = HorusFileHelperLibrary)
	static bool BytesToStringArray(const TArray<uint8>& Bytes, TArray<FString>& OutStrings);

	/*
	* Converts an array of compressed Bytes to an array of Strings.
	*/
	UFUNCTION(BlueprintCallable, Category = HorusFileHelperLibrary)
	static bool CompressedBytesToStringArray(const TArray<uint8>& CompressedBytes, TArray<FString>& OutStrings);

	/*
	* Loads compressed binary file as an array of strings.
	*/
	UFUNCTION(BlueprintCallable, Category = HorusFileHelperLibrary)
		static bool LoadCompressedBinaryFileToStringArray(const FString& FilePath, TArray<FString>& OutStrings);

	/*
	* Loads compressed binary file as an array of strings and stores the compressed bytes for usage later.
	*/
	UFUNCTION(BlueprintCallable, Category = HorusFileHelperLibrary)
		static bool LoadCompressedBinaryFileToStringArrayAndBytes(const FString& FilePath, TArray<FString>& OutStrings, TArray<uint8>& OutCompressedBytes);


	/*
	* Saves an array of strings to a compressed binary file.
	*/
	UFUNCTION(BlueprintCallable, Category = HorusFileHelperLibrary)
		static bool SaveStringArrayToCompressedBinaryFile(const FString& FilePath, UPARAM(ref) TArray<FString>& Strings);


};
