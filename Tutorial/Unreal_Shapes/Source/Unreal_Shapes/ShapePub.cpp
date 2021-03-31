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
#include <rti/core/rticore.hpp>
#include <rti/core/QosProviderParams.hpp>


// Sets default values
AShapePub::AShapePub()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CustomStaticMesh"));
	RootComponent = StaticMesh;

}

// Called when the game starts or when spawned
void AShapePub::BeginPlay()
{
	Super::BeginPlay();
	
    /* Construct the fully qualified name for the configuration file (XML) location */
    FString xmlFile = FPaths::Combine(FPaths::ProjectContentDir(), QOS_URL);
    /* Read the configuration file and set the defaults*/
    rti::core::QosProviderParams provider_name;
    provider_name.url_profile({ TCHAR_TO_UTF8(*xmlFile) });
    dds::core::QosProvider::Default().extensions().default_provider_params(provider_name);

    /* Initialize the dynamic data type */
    const dds::core::xtypes::DynamicType& myType = dds::core::QosProvider::Default().extensions().type(TCHAR_TO_UTF8(*TYPE_NAME));

    /* Create a domain participant */
    /* Let’s see if a domain participant already exists */
    dds::domain::DomainParticipant participant = dds::domain::find(DomainID);
    /* If not create one */
    if (participant == dds::core::null)
    {
        participant = dds::domain::DomainParticipant(DomainID);
    }

    /* Get a reference to the implicit publisher*/
    dds::pub::Publisher publisher = rti::pub::implicit_publisher(participant);

    /* Create the topic with the configured name for the participant and dynamic type */
    /* Find the topic */
    auto topic = dds::topic::find<dds::topic::Topic<dds::core::xtypes::DynamicData>>(participant, TCHAR_TO_UTF8(*TopicName));
    /* If the topic doesn’t exist create it */
    if (topic == dds::core::null)
    {
        topic = dds::topic::Topic<dds::core::xtypes::DynamicData>(participant,
            TCHAR_TO_UTF8(*TopicName), myType);
    }

    /* Create the data writer*/
    std::vector<dds::pub::DataWriter<dds::core::xtypes::DynamicData> > writers;

    /* Get the list of writers*/
    int writer_count = dds::pub::find<dds::pub::DataWriter<dds::core::xtypes::DynamicData> >(
        publisher,
        TCHAR_TO_UTF8(*TopicName),
        std::back_inserter(writers));

    /* All we need is at least one writer. If there are multiple let’s use the first
       one returned. If no readers are found we create one
     */
    if (writer_count)
    {
        writer = writers[0];
    }
    else
    {
        writer = dds::pub::DataWriter<dds::core::xtypes::DynamicData>(publisher, topic);
    }

    /* Initialize direction and set initial location */
    Direction = FVector(FMath::RandRange(-100.0f, 100.0f), FMath::RandRange(-100.0f, 100.0f), FMath::RandRange(-100.0f, 100.0f));
    SetActorLocation(FVector(FMath::RandRange(MinBox.X, MaxBox.X), FMath::RandRange(MinBox.Y, MaxBox.Y), FMath::RandRange(MinBox.Z, MaxBox.Z)));

    /* Initialize the sample and set the size and color */
    sample = new dds::core::xtypes::DynamicData(myType);
    sample->value<int32_t>("shapesize", 30);
    sample->value<std::string>("color", TCHAR_TO_UTF8(*Color));

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
    if (Location.X > MaxBox.X) { Location.X = MaxBox.X; Direction.X *= -1; }
    if (Location.Y > MaxBox.Y) { Location.Y = MaxBox.Y; Direction.Y *= -1; }
    if (Location.Z > MaxBox.Z) { Location.Z = MaxBox.Z; Direction.Z *= -1; }
    if (Location.X < MinBox.X) { Location.X = MinBox.X; Direction.X *= -1; }
    if (Location.Y < MinBox.Y) { Location.Y = MinBox.Y; Direction.Y *= -1; }
    if (Location.Z < MinBox.Z) { Location.Z = MinBox.Z; Direction.Z *= -1; }

    /* Only publish if we have a valid writer */
    if (writer != dds::core::null)
    {
        /* Set the values and adjust for the different origin */
        sample->value<int32_t>("x", MaxBox.Y - Location.Y);
        sample->value<int32_t>("y", MaxBox.Z - Location.Z);
        sample->value<int32_t>("z", Location.X);
        writer->write(*sample);
    }

}

// Called to bind functionality to input
void AShapePub::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AShapePub::Initialize(int32_t myDomainId, FString myColor)
{
    Color = myColor;
    DomainID = myDomainId;

    if (myColor == "PURPLE") StaticMesh->SetMaterial(0, Purple);
    else if (myColor == "BLUE") StaticMesh->SetMaterial(0, Blue);
    else if (myColor == "RED") StaticMesh->SetMaterial(0, Red);
    else if (myColor == "GREEN") StaticMesh->SetMaterial(0, Green);
    else if (myColor == "YELLOW") StaticMesh->SetMaterial(0, Yellow);
    else if (myColor == "CYAN") StaticMesh->SetMaterial(0, Cyan);
    else if (myColor == "MAGENTA") StaticMesh->SetMaterial(0, Magenta);
    else if (myColor == "ORANGE") StaticMesh->SetMaterial(0, Orange);
    else StaticMesh->SetMaterial(0, Default);
}

void AShapePub::StopPublish()
{
    Destroy();
    GEngine->ForceGarbageCollection(true);
}



