/*
 * (c) 2025 Copyright, Real-Time Innovations, Inc. (RTI) All rights reserved.
 *
 * RTI grants Licensee a license to use, modify, compile, and create derivative
 * works of the software solely for use with RTI Connext DDS.  Licensee may
 * redistribute copies of the software provided that all such copies are
 * subject to this license. The software is provided "as is", with no warranty
 * of any type, including any warranty for fitness for any purpose. RTI is
 * under no obligation to maintain or support the software.  RTI shall not be
 * liable for any incidental or consequential damages arising out of the use or
 * inability to use the software.
 */


#include "BaseUtilities.h"

#include "ndds/ndds_cpp.h"

#include "UObject/NoExportTypes.h"
#include "Engine/Engine.h" // For GEngine->AddOnScreenDebugMessage
#include "Engine/World.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/PlayerController.h"

DEFINE_LOG_CATEGORY(LogDDS);


class UELoggerDevice : public NDDSConfigLoggerDevice {
public:
    UELoggerDevice() {
    }
    ~UELoggerDevice() {
    }
    virtual void write(const NDDS_Config_LogMessage* message) {

        switch (message->level)
        {
        case NDDS_Config_LogLevel::NDDS_CONFIG_LOG_LEVEL_DEBUG:
            UE_LOG(LogDDS, Verbose, TEXT("[DDS] %s"), UTF8_TO_TCHAR(message->text));
            break;
        case NDDS_Config_LogLevel::NDDS_CONFIG_LOG_LEVEL_STATUS_LOCAL:
        case NDDS_Config_LogLevel::NDDS_CONFIG_LOG_LEVEL_STATUS_REMOTE:
            UE_LOG(LogDDS, Log, TEXT("[DDS] %s"), UTF8_TO_TCHAR(message->text));
            break;
        case NDDS_Config_LogLevel::NDDS_CONFIG_LOG_LEVEL_WARNING:
            UE_LOG(LogDDS, Warning, TEXT("[DDS] %s"), UTF8_TO_TCHAR(message->text));
            break;
        case NDDS_Config_LogLevel::NDDS_CONFIG_LOG_LEVEL_ERROR:
            UE_LOG(LogDDS, Error, TEXT("[DDS] %s"), UTF8_TO_TCHAR(message->text));
            break;
        case NDDS_Config_LogLevel::NDDS_CONFIG_LOG_LEVEL_FATAL_ERROR:
            UE_LOG(LogDDS, Fatal, TEXT("[DDS] %s"), UTF8_TO_TCHAR(message->text));
            break;
        default:
            UE_LOG(LogDDS, Log, TEXT("[DDS] %s"), UTF8_TO_TCHAR(message->text));
            break;
        }

    }
};

static UELoggerDevice _ddsLogger;

/*
 * Initialize logger
 */
void BeginGameSession() {

    // Redirect Connext DDS logging to the UE logger
    NDDSConfigLogger* ddsLogger;
    ddsLogger = NDDSConfigLogger::get_instance();

    if (!ddsLogger->set_output_device(&_ddsLogger)) {
        UE_LOG(LogDDS, Error, TEXT("*** ShapeSub could not set logger to UE_LOG"));
    }
}

/*
 *  Used to stop an application running in PIE without exiting the Unreal Engine IDE.
 */
void StopGameSession(UObject* WorldContextObject)
{
    if (!WorldContextObject)
    {
        UE_LOG(LogTemp, Warning, TEXT("StopGameSession failed: WorldContextObject is null"));
        return;
    }

    UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject);
    if (!World)
    {
        UE_LOG(LogTemp, Warning, TEXT("StopGameSession failed: could not resolve world"));
        return;
    }

    // Only trigger in PIE or game world
    if (World->WorldType != EWorldType::PIE && World->WorldType != EWorldType::Game)
    {
        UE_LOG(LogTemp, Warning, TEXT("StopGameSession skipped: not PIE/Game world"));
        return;
    }

    // Get first player controller
    APlayerController* PC = UGameplayStatics::GetPlayerController(World, 0);
    if (!PC)
    {
        UE_LOG(LogTemp, Warning, TEXT("StopGameSession failed: no player controller found"));
        return;
    }

    // Defer quitting slightly to ensure PIE world is fully ready
    FTimerHandle TimerHandle;
    World->GetTimerManager().SetTimer(TimerHandle, [World, PC]()
        {
            UE_LOG(LogTemp, Log, TEXT("Quitting game now"));
            UKismetSystemLibrary::QuitGame(World, PC, EQuitPreference::Quit, false);
        }, 0.01f, false);   // 0.01s
}