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

#include "ShapeSub.h"
#include <rti/core/rticore.hpp>
#include <rti/core/QosProviderParams.hpp>


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

    /* Construct the fully qualified name for the configuration file (XML)
     * location */
    FString xmlFile = FPaths::Combine(FPaths::ProjectContentDir(), QOS_URL);
    /* Read the configuration file and set the defaults*/
    rti::core::QosProviderParams provider_name;
    provider_name.url_profile({ TCHAR_TO_UTF8(*xmlFile) });
    dds::core::QosProvider::Default().extensions().default_provider_params(
            provider_name);

    /* Initialize the dynamic data type */
    const dds::core::xtypes::DynamicType& myType =
            dds::core::QosProvider::Default().extensions().type(
                    TCHAR_TO_UTF8(*TYPE_NAME));

    /* Create a domain participant */
    /* Let’s see if a domain participant already exists */
    dds::domain::DomainParticipant participant = dds::domain::find(DomainID);
    /* If not create one */
    if (participant == dds::core::null) {
        participant = dds::domain::DomainParticipant(DomainID);
    }


    /* Get a reference to the implicit subscriber */
    dds::sub::Subscriber subscriber =
            rti::sub::implicit_subscriber(participant);

    /* Create the topic with the configured name for the participant and dynamic
     * type */
    /* Find the topic */
    auto topic =
            dds::topic::find<dds::topic::Topic<dds::core::xtypes::DynamicData>>(
                    participant,
                    TCHAR_TO_UTF8(*TopicName));
    /* If the topic doesn’t exist create it */
    if (topic == dds::core::null) {
        topic = dds::topic::Topic<dds::core::xtypes::DynamicData>(
                participant,
                TCHAR_TO_UTF8(*TopicName),
                myType);
    }


    /* Create the data reader */
    /* List of readers returned by the find function */
    std::vector<dds::sub::DataReader<dds::core::xtypes::DynamicData>> readers;

    /* Get the list of readers */
    int reader_count = dds::sub::find<
            dds::sub::DataReader<dds::core::xtypes::DynamicData>>(
            subscriber,
            TCHAR_TO_UTF8(*TopicName),
            std::back_inserter(readers));

    /* All we need is at least one reader. If there are multiple let’s use the
       first one returned. If no readers are found we create one
     */
    if (reader_count) {
        reader = readers[0];
    } else {
        reader = dds::sub::DataReader<dds::core::xtypes::DynamicData>(
                subscriber,
                topic);
    }
}

// Called every frame
void AShapeSub::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    FString Filter("color MATCH '" + Color + "'");
    dds::sub::cond::QueryCondition query_condition(
            dds::sub::Query(reader, TCHAR_TO_UTF8(*Filter)),
            dds::sub::status::DataState::any());

    /* Take all the samples from the queue */
    rti::sub::LoanedSamples<dds::core::xtypes::DynamicData> samples =
            reader.select().condition(query_condition).take();


    /* Process each sample which is valid */
    for (const auto& sample : samples) {
        if (sample->info().valid()) {
            /* Read the values we are interested (X and Y) from
               the dynamic data */
            int32 x = sample->data().value<int32>("x");
            int32 y = sample->data().value<int32>("y");
            int32 z = sample->data().value<int32>("z");
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

// Called to bind functionality to input
void AShapeSub::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);
}
