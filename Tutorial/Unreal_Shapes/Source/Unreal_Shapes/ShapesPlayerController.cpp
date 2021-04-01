/*
 * (c) 2021 Copyright, Real-Time Innovations, Inc. (RTI) All rights reserved.
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

#include "ShapesPlayerController.h"

void AShapesPlayerController::SetupInputComponent()
{
    Super::SetupInputComponent();

    InputComponent->BindAction(
            "Publisher",
            IE_Pressed,
            this,
            &AShapesPlayerController::HandleKey);
}

bool AShapesPlayerController::ToggleSquarePublisher(FString color)
{
    bool retval = false;
    UWorld* World = GetWorld();
    FActorSpawnParameters SpawnParams;
    SpawnParams.bNoFail = TRUE; /* Spawn should always succeed even in case of a
                                   collision */

    /* If there is no publisher create one*/
    if (Publisher == NULL) {
        const FTransform SpawnLocAndRotation;
        Publisher = World->SpawnActorDeferred<AActor>(
                SquarePub,
                SpawnLocAndRotation);
        AShapePub* s = Cast<AShapePub>(Publisher);
        s->Initialize(DomainID, color);
        s->FinishSpawning(SpawnLocAndRotation);
        retval = true;  // Publisher is running
    } else {
        // We have a valid publisher to toggle destray the publisher */
        AShapePub* s = Cast<AShapePub>(Publisher);
        s->StopPublish();
        Publisher = NULL;
        retval = false;  // No publisher running
    }
    return retval;
}
void AShapesPlayerController::HandleKey()
{
    ToggleSquarePublisher("RED");
}