// ©Justin Camden 2019, all rights reserved.


#include "HorusStandardPlayerController.h"

void AHorusStandardPlayerController::Client_BeginResolvingPlayerActions_Implementation()
{
	bIsResolvingActions = true;
}

bool AHorusStandardPlayerController::Client_BeginResolvingPlayerActions_Validate()
{
	return (!bIsResolvingActions);
}
