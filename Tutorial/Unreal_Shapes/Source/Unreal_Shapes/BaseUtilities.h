#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"


DECLARE_LOG_CATEGORY_EXTERN(LogDDS, Log, All);


void BeginGameSession();

void StopGameSession(UObject* WorldContextObject);
