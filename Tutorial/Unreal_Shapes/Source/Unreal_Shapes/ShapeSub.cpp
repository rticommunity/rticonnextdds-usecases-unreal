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

#include "ShapeSub.h"
#include "BaseUtilities.h"


// Sets default values
AShapeSub::AShapeSub()
{
    // Set this pawn to call Tick() every frame.  You can turn this off to
    // improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

    StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(
            TEXT("CustomStaticMesh"));
    RootComponent = StaticMesh;
}

// Called when the game starts or when spawned
void AShapeSub::BeginPlay()
{
    Super::BeginPlay();

    // Initialization
    BeginGameSession();

    /* Create a domain participant */
    /* Let�s see if a domain participant already exists */
    participant = DDSTheParticipantFactory->lookup_participant(DomainID);

    /* If not create one */
    if (participant == NULL) {
        participant = DDSTheParticipantFactory->create_participant(DomainID, DDS_PARTICIPANT_QOS_DEFAULT, NULL, DDS_STATUS_MASK_NONE);

        if (participant == NULL) {
            UE_LOG(LogDDS, Error, TEXT("ShapeSub failed to create DomainParticipant"));
            StopGameSession(this);
        }

        // ignore your own publications
        participant->ignore_participant(participant->get_instance_handle());
    }

    /* register type with participant if not registered */
    // Register type if not registered
    if (participant->get_typecode(TCHAR_TO_ANSI(*TYPE_NAME)) == NULL) {
        ShapeTypeExtended3DTypeSupport::register_type(participant);
        UE_LOG(LogDDS, Log, TEXT("ShapeSub type \"%s\" registered"), *TYPE_NAME);
    }

    /* Get a reference to the implicit subscriber*/
    subscriber = participant->get_implicit_subscriber();

    /* Create the topic if not already created */
    DDSTopic* topic = (DDSTopic*)participant->lookup_topicdescription(TCHAR_TO_ANSI(*TopicName));

    if (topic == NULL) {
        topic = participant->create_topic(TCHAR_TO_ANSI(*TopicName), TCHAR_TO_ANSI(*TYPE_NAME), DDS_TOPIC_QOS_DEFAULT, NULL, DDS_STATUS_MASK_NONE);

        if (topic == NULL) {
            UE_LOG(LogDDS, Error, TEXT("ShapeSub failed to create Topic \"%s\" for type \"%s\" "), *TopicName, *TYPE_NAME);
            StopGameSession(this);
            return;
        }

        UE_LOG(LogDDS, Log, TEXT("ShapeSub created Topic \"%s\""), *TopicName);
    }

    /* Create the data reader */
    DDSDataReader* tmpreader = subscriber->create_datareader(topic, DDS_DATAREADER_QOS_DEFAULT, NULL, DDS_STATUS_MASK_NONE);
    reader = ShapeTypeExtended3DDataReader::narrow(tmpreader);

    if (reader == NULL) {
        UE_LOG(LogDDS, Error, TEXT("ShapeSub failed to create DataReader for Topic \"%s\""), *TopicName);
        StopGameSession(this);
        return;
    }

    UE_LOG(LogDDS, Log, TEXT("ShapeSub created DataReader for Topic \"%s\""), *TopicName);
}

// Called every frame
void AShapeSub::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    if (reader) {
        ShapeTypeExtended3DSeq shapeSeq;
        DDS_SampleInfoSeq infoSeq;

        // Possible that multiple samples have been received since last poll
        // Data is received in a sequence (variable-length array)
        if (reader->take(shapeSeq, infoSeq) == DDS_RETCODE_OK) {

            // get subscribed color
            char* subcolor = TCHAR_TO_ANSI(*Color);

            // Only need to copy out the value of the last received value
            for (int i = 0; i < shapeSeq.length(); ++i) {

                // Always need to check for data validity
                if (infoSeq[i].valid_data) {

                    if (strcmp(shapeSeq[i].color, subcolor)==0) {
                        int32 x = shapeSeq[i].x;
                        int32 y = shapeSeq[i].y;
                        int32 z = shapeSeq[i].z;
                        /* Set the location. We want the shape to move horizontal
                           and vertical. Set the values and adjust for the different
                           origin, In order for publisher and subscriber to be at the
                           same location from the maximum box size defined in ShapePub
                         */
                        FVector Location(z, 260 - x, 270 - y);
                        SetActorLocation(Location);
                    }
                }
            }

            // Loaned storage for data/info is returned to the DataReader
            reader->return_loan(shapeSeq, infoSeq);
        }
    }
}


void AShapeSub::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
    Super::EndPlay(EndPlayReason);

    /* Delete the reader */
    DDSDataReader* tmpReader = reader;
    reader = NULL;
    subscriber->delete_datareader(tmpReader);

    Destroy();
    GEngine->ForceGarbageCollection(true);
}

