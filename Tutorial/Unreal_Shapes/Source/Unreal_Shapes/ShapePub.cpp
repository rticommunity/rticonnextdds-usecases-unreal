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

#include "ShapePub.h"
#include "BaseUtilities.h"


// Sets default values
AShapePub::AShapePub()
{
    // Set this pawn to call Tick() every frame.  You can turn this off to
    // improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

    StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(
            TEXT("CustomStaticMesh"));
    RootComponent = StaticMesh;
}

// Called when the game starts or when spawned
void AShapePub::BeginPlay()
{
    Super::BeginPlay();

    UE_LOG(LogDDS, Log, TEXT("AShapePub BeginPlay called"));

    // Initialization
    BeginGameSession();

    /* Create a domain participant */
    /* Let’s see if a domain participant already exists */
    participant = DDSTheParticipantFactory->lookup_participant(DomainID);

    /* If not create one */
    if (participant == NULL) {
        participant = DDSTheParticipantFactory->create_participant(DomainID, DDS_PARTICIPANT_QOS_DEFAULT, NULL, DDS_STATUS_MASK_NONE);

        if (participant == NULL) {
            UE_LOG(LogDDS, Error, TEXT("ShapePub failed to create DomainParticipant"));
            StopGameSession(this);
        }

        // ignore your own subscriptions
        participant->ignore_participant(participant->get_instance_handle());
    }

    /* register type with participant if not registered */
    // Register type if not registered
    if (participant->get_typecode(TCHAR_TO_ANSI(*TYPE_NAME)) == NULL) {
        ShapeTypeExtended3DTypeSupport::register_type(participant);
        UE_LOG(LogDDS, Log, TEXT("ShapePub type \"%s\" registered"), *TYPE_NAME);
    }

    /* Get a reference to the implicit publisher*/
    publisher = participant->get_implicit_publisher();

    /* Create the topic if not already created */
    DDSTopic* topic = (DDSTopic*) participant->lookup_topicdescription(TCHAR_TO_ANSI(*TopicName));

    if (topic == NULL) {
        topic = participant->create_topic(TCHAR_TO_ANSI(*TopicName), TCHAR_TO_ANSI(*TYPE_NAME), DDS_TOPIC_QOS_DEFAULT, NULL, DDS_STATUS_MASK_NONE);

        if (topic == NULL) {
            UE_LOG(LogDDS, Error, TEXT("ShapePub failed to create Topic \"%s\" for type \"%s\" "), *TopicName, *TYPE_NAME);
            StopGameSession(this);
            return;
        }

        UE_LOG(LogDDS, Log, TEXT("ShapePub created Topic \"%s\""), *TopicName);
    }

    /* Create the data writer */
    DDSDataWriter* tmpwriter = publisher->create_datawriter(topic, DDS_DATAWRITER_QOS_DEFAULT, NULL, DDS_STATUS_MASK_NONE);
    writer = ShapeTypeExtended3DDataWriter::narrow(tmpwriter);


    if (writer == NULL) {
        UE_LOG(LogDDS, Error, TEXT("ShapePub failed to create DataWriter for Topic \"%s\""), *TopicName);
        StopGameSession(this);
        return;
    }

    UE_LOG(LogDDS, Log, TEXT("ShapePub created DataWriter for Topic \"%s\""), *TopicName);

    /* Initialize direction and set initial location */
    Direction =
            FVector(FMath::RandRange(-100.0f, 100.0f),
                    FMath::RandRange(-100.0f, 100.0f),
                    FMath::RandRange(-100.0f, 100.0f));
    SetActorLocation(
            FVector(FMath::RandRange(MinBox.X, MaxBox.X),
                    FMath::RandRange(MinBox.Y, MaxBox.Y),
                    FMath::RandRange(MinBox.Z, MaxBox.Z)));

    /* Initialize the sample and set the size and color */
    sample = ShapeTypeExtended3DTypeSupport::create_data();
    sample->shapesize = 30;
    sample->color = DDS_String_dup(TCHAR_TO_UTF8(*Color));
}

// Called every frame
void AShapePub::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    /* AddActorLocalOffset returns information if the move resulted
       in a hit. For now this is ignored.
     */
    FHitResult Hit;

    /* Move the shape */
    AddActorLocalOffset(Direction * DeltaTime, false, &Hit);

    /* Get the current location and publish it */
    FVector Location = GetActorLocation();
    /* If we hit any of the bounds change direction */
    if (Location.X > MaxBox.X) {
        Location.X = MaxBox.X;
        Direction.X *= -1;
    }
    if (Location.Y > MaxBox.Y) {
        Location.Y = MaxBox.Y;
        Direction.Y *= -1;
    }
    if (Location.Z > MaxBox.Z) {
        Location.Z = MaxBox.Z;
        Direction.Z *= -1;
    }
    if (Location.X < MinBox.X) {
        Location.X = MinBox.X;
        Direction.X *= -1;
    }
    if (Location.Y < MinBox.Y) {
        Location.Y = MinBox.Y;
        Direction.Y *= -1;
    }
    if (Location.Z < MinBox.Z) {
        Location.Z = MinBox.Z;
        Direction.Z *= -1;
    }

    /* Only publish if we have a valid writer */
    if (writer != NULL) {
        /* Set the values and adjust for the different origin */
        sample->x = MaxBox.Y - Location.Y;
        sample->y =  MaxBox.Z - Location.Z;
        sample->z = Location.X;
        writer->write(*sample, DDS_HANDLE_NIL);
    }
}

// Called to bind functionality to input
void AShapePub::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void AShapePub::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
    Super::EndPlay(EndPlayReason);

    /* Delete the writer */
    DDSDataWriter* tmpWriter = writer;
    writer = NULL;
    publisher->delete_datawriter(tmpWriter);

    Destroy();
    GEngine->ForceGarbageCollection(true);
}
