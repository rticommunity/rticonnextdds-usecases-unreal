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


#include "ShapesSubscriberManager.h"
#include "ShapeSubDynamic.h"
#include "BaseUtilities.h"


AShapesSubscriberManager::AShapesSubscriberManager()
{
    PrimaryActorTick.bCanEverTick = true;
}

void AShapesSubscriberManager::BeginPlay()
{
    Super::BeginPlay();

    UE_LOG(LogDDS, Log, TEXT("AShapesSubscriberManager BeginPlay called"));

    // Initialization
    BeginGameSession();

    /* Create a domain participant */
    /* Let’s see if a domain participant already exists */
    participant = DDSTheParticipantFactory->lookup_participant(DomainID);

    /* If not create one */
    if (participant == NULL) {
        participant = DDSTheParticipantFactory->create_participant(DomainID, DDS_PARTICIPANT_QOS_DEFAULT, NULL, DDS_STATUS_MASK_NONE);

        if (participant == NULL) {
            UE_LOG(LogDDS, Error, TEXT("AShapesSubscriberManager failed to create DomainParticipant"));
            StopGameSession(this);
        }

        // ignore your own publications
        participant->ignore_participant(participant->get_instance_handle());
    }

    /* register type with participant if not registered */
    // Register type if not registered
    if (participant->get_typecode(TCHAR_TO_ANSI(*TYPE_NAME)) == NULL) {
        ShapeTypeExtended3DTypeSupport::register_type(participant);
        UE_LOG(LogDDS, Log, TEXT("AShapesSubscriberManager type \"%s\" registered"), *TYPE_NAME);
    }

    /* Get a reference to the implicit subscriber*/
    subscriber = participant->get_implicit_subscriber();

    /* Create the topic with the configured name for the participant and dynamic
     * type */
    /* Find the topic */
    DDSTopic* Squaretopic = (DDSTopic*)participant->lookup_topicdescription("Square");

    if (Squaretopic == NULL) {
        Squaretopic = participant->create_topic("Square", TCHAR_TO_ANSI(*TYPE_NAME), DDS_TOPIC_QOS_DEFAULT, NULL, DDS_STATUS_MASK_NONE);

        if (Squaretopic == NULL) {
            UE_LOG(LogDDS, Error, TEXT("AShapesSubscriberManager failed to create Topic \"Square\" for type \"%s\" "), *TYPE_NAME);
            StopGameSession(this);
            return;
        }

        UE_LOG(LogDDS, Log, TEXT("AShapesSubscriberManager created Topic \"Square\""));
    }

    /* Create the topic with the configured name for the participant and dynamic
     * type */
    /* Find the topic */
    DDSTopic* Circletopic = (DDSTopic*)participant->lookup_topicdescription("Circle");

    if (Circletopic == NULL) {
        Circletopic = participant->create_topic("Circle", TCHAR_TO_ANSI(*TYPE_NAME), DDS_TOPIC_QOS_DEFAULT, NULL, DDS_STATUS_MASK_NONE);

        if (Circletopic == NULL) {
            UE_LOG(LogDDS, Error, TEXT("AShapesSubscriberManager failed to create Topic \"Circle\" for type \"%s\" "), *TYPE_NAME);
            StopGameSession(this);
            return;
        }

        UE_LOG(LogDDS, Log, TEXT("AShapesSubscriberManager created Topic \"Circle\""));
    }

    /* Create the topic with the configured name for the participant and dynamic
     * type */
    /* Find the topic */
    DDSTopic* Triangletopic = (DDSTopic*)participant->lookup_topicdescription("Triangle");

    if (Triangletopic == NULL) {
        Triangletopic = participant->create_topic("Triangle", TCHAR_TO_ANSI(*TYPE_NAME), DDS_TOPIC_QOS_DEFAULT, NULL, DDS_STATUS_MASK_NONE);

        if (Triangletopic == NULL) {
            UE_LOG(LogDDS, Error, TEXT("AShapesSubscriberManager failed to create Topic \"Triangle\" for type \"%s\" "), *TYPE_NAME);
            StopGameSession(this);
            return;
        }

        UE_LOG(LogDDS, Log, TEXT("AShapesSubscriberManager created Topic \"Triangle\""));
    }

    /* Create the data reader */
    DDSDataReader* tmpreader = subscriber->create_datareader(Squaretopic, DDS_DATAREADER_QOS_DEFAULT, NULL, DDS_STATUS_MASK_NONE);
    SquareReader = ShapeTypeExtended3DDataReader::narrow(tmpreader);

    if (SquareReader == NULL) {
        UE_LOG(LogDDS, Error, TEXT("AShapesSubscriberManager failed to create DataReader for Topic \"Square\""));
        StopGameSession(this);
        return;
    }

    UE_LOG(LogDDS, Log, TEXT("AShapesSubscriberManager created DataReader for Topic \"Square\""));


    /* Create the data reader */
    tmpreader = subscriber->create_datareader(Circletopic, DDS_DATAREADER_QOS_DEFAULT, NULL, DDS_STATUS_MASK_NONE);
    CircleReader = ShapeTypeExtended3DDataReader::narrow(tmpreader);

    if (CircleReader == NULL) {
        UE_LOG(LogDDS, Error, TEXT("AShapesSubscriberManager failed to create DataReader for Topic \"Circle\""));
        StopGameSession(this);
        return;
    }

    UE_LOG(LogDDS, Log, TEXT("AShapesSubscriberManager created DataReader for Topic \"Circle\""));


    /* Create the data reader */
    tmpreader = subscriber->create_datareader(Triangletopic, DDS_DATAREADER_QOS_DEFAULT, NULL, DDS_STATUS_MASK_NONE);
    TriangleReader = ShapeTypeExtended3DDataReader::narrow(tmpreader);

    if (TriangleReader == NULL) {
        UE_LOG(LogDDS, Error, TEXT("AShapesSubscriberManager failed to create DataReader for Topic \"Triangle\""));
        StopGameSession(this);
        return;
    }

    UE_LOG(LogDDS, Log, TEXT("AShapesSubscriberManager created DataReader for Topic \"Triangle\""));

}


void AShapesSubscriberManager::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    UWorld* World = GetWorld();
    FActorSpawnParameters SpawnParams;
    SpawnParams.bNoFail = TRUE;

    if (SquareReader != NULL) {

        ShapeTypeExtended3DSeq shapeSeq;
        DDS_SampleInfoSeq infoSeq;

        // Get only samples for instances that have not ever been seen (new colors)
        if (SquareReader->read(shapeSeq, infoSeq, DDS_LENGTH_UNLIMITED, DDS_ANY_SAMPLE_STATE,
            DDS_NEW_VIEW_STATE, DDS_ALIVE_INSTANCE_STATE) == DDS_RETCODE_OK) {

            UE_LOG(LogDDS, Log, TEXT("AShapesSubscriberManager Got new color for Topic \"Square\""));

            for (int i=0; i<shapeSeq.length(); ++i) {
                if (infoSeq[i].valid_data) {
                    /* Set the color of the new instance and spawn the
                     * subscriber */
                    FString color(shapeSeq[i].color);
                    FTransform SpawnLocAndRotation;
                    SpawnLocAndRotation.SetLocation(FVector(shapeSeq[i].x, shapeSeq[i].y, shapeSeq[i].z));

                    AActor* a = World->SpawnActorDeferred<AActor>(
                        SquareSub,
                        SpawnLocAndRotation, nullptr, nullptr,
                        ESpawnActorCollisionHandlingMethod::AlwaysSpawn);
                    AShapeSubDynamic* s = Cast<AShapeSubDynamic>(a);
                    s->Initialize(
                            SquareReader,
                            infoSeq[i].instance_handle,
                            color);
                    s->FinishSpawning(SpawnLocAndRotation);

                    UE_LOG(LogDDS, Log, TEXT("AShapesSubscriberManager color: %s"), *color);
                }
            }

            SquareReader->return_loan(shapeSeq, infoSeq);
        }

    }

    if (CircleReader != NULL) {

        ShapeTypeExtended3DSeq shapeSeq;
        DDS_SampleInfoSeq infoSeq;

        // Get only samples for instances that have not ever been seen (new colors)
        if (CircleReader->read(shapeSeq, infoSeq, DDS_LENGTH_UNLIMITED, DDS_ANY_SAMPLE_STATE,
            DDS_NEW_VIEW_STATE, DDS_ALIVE_INSTANCE_STATE) == DDS_RETCODE_OK) {

            UE_LOG(LogDDS, Log, TEXT("AShapesSubscriberManager Got new color for Topic \"Circle\""));

            for (int i = 0; i < shapeSeq.length(); ++i) {
                if (infoSeq[i].valid_data) {
                    /* Set the color of the new instance and spawn the
                     * subscriber */
                    FString color(shapeSeq[i].color);
                    FTransform SpawnLocAndRotation;
                    SpawnLocAndRotation.SetLocation(FVector(shapeSeq[i].x, shapeSeq[i].y, shapeSeq[i].z));

                    AActor* a = World->SpawnActorDeferred<AActor>(
                        CircleSub,
                        SpawnLocAndRotation, nullptr, nullptr,
                        ESpawnActorCollisionHandlingMethod::AlwaysSpawn);
                    AShapeSubDynamic* s = Cast<AShapeSubDynamic>(a);
                    s->Initialize(
                        CircleReader,
                        infoSeq[i].instance_handle,
                        color);
                    s->FinishSpawning(SpawnLocAndRotation);

                    UE_LOG(LogDDS, Log, TEXT("AShapesSubscriberManager color: %s"), *color);
                }
            }

            CircleReader->return_loan(shapeSeq, infoSeq);
        }
    }

    if (TriangleReader != NULL) {

        ShapeTypeExtended3DSeq shapeSeq;
        DDS_SampleInfoSeq infoSeq;

        // Get only samples for instances that have not ever been seen (new colors)
        if (TriangleReader->read(shapeSeq, infoSeq, DDS_LENGTH_UNLIMITED, DDS_ANY_SAMPLE_STATE,
            DDS_NEW_VIEW_STATE, DDS_ALIVE_INSTANCE_STATE) == DDS_RETCODE_OK) {

            UE_LOG(LogDDS, Log, TEXT("AShapesSubscriberManager Got new color for Topic \"Triangle\""));

            for (int i = 0; i < shapeSeq.length(); ++i) {
                if (infoSeq[i].valid_data) {
                    /* Set the color of the new instance and spawn the
                     * subscriber */
                    FString color(shapeSeq[i].color);
                    FTransform SpawnLocAndRotation;
                    SpawnLocAndRotation.SetLocation(FVector(shapeSeq[i].x, shapeSeq[i].y, shapeSeq[i].z));

                    AActor* a = World->SpawnActorDeferred<AActor>(
                        TriangleSub,
                        SpawnLocAndRotation, nullptr, nullptr,
                        ESpawnActorCollisionHandlingMethod::AlwaysSpawn);
                    AShapeSubDynamic* s = Cast<AShapeSubDynamic>(a);
                    s->Initialize(
                        TriangleReader,
                        infoSeq[i].instance_handle,
                        color);
                    s->FinishSpawning(SpawnLocAndRotation);

                    UE_LOG(LogDDS, Log, TEXT("AShapesSubscriberManager color: %s"), *color);
                }
            }
        }

        TriangleReader->return_loan(shapeSeq, infoSeq);
    }
}

void AShapesSubscriberManager::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
    Super::EndPlay(EndPlayReason);

    /* Delete the readers */
    DDSDataReader* tmpReader = SquareReader;
    SquareReader = NULL;
    subscriber->delete_datareader(tmpReader);

    tmpReader = CircleReader;
    CircleReader = NULL;
    subscriber->delete_datareader(tmpReader);

    tmpReader = TriangleReader;
    TriangleReader = NULL;
    subscriber->delete_datareader(tmpReader);

    Destroy();
    GEngine->ForceGarbageCollection(true);
}
