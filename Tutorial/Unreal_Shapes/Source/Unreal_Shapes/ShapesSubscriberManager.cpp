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

AShapesSubscriberManager::AShapesSubscriberManager()
{
    PrimaryActorTick.bCanEverTick = true;
}

void AShapesSubscriberManager::BeginPlay()
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
    auto Squaretopic =
            dds::topic::find<dds::topic::Topic<dds::core::xtypes::DynamicData>>(
                    participant,
                    "Square");
    /* If the topic doesn’t exist create it */
    if (Squaretopic == dds::core::null) {
        Squaretopic = dds::topic::Topic<dds::core::xtypes::DynamicData>(
                participant,
                "Square",
                myType);
    }

    /* Create the topic with the configured name for the participant and dynamic
     * type */
    /* Find the topic */
    auto Circletopic =
            dds::topic::find<dds::topic::Topic<dds::core::xtypes::DynamicData>>(
                    participant,
                    "Circle");
    /* If the topic doesn’t exist create it */
    if (Circletopic == dds::core::null) {
        Circletopic = dds::topic::Topic<dds::core::xtypes::DynamicData>(
                participant,
                "Circle",
                myType);
    }

    /* Create the topic with the configured name for the participant and dynamic
     * type */
    /* Find the topic */
    auto Triangletopic =
            dds::topic::find<dds::topic::Topic<dds::core::xtypes::DynamicData>>(
                    participant,
                    "Triangle");
    /* If the topic doesn’t exist create it */
    if (Triangletopic == dds::core::null) {
        Triangletopic = dds::topic::Topic<dds::core::xtypes::DynamicData>(
                participant,
                "Triangle",
                myType);
    }


    /* Create the data reader */
    /* List of readers returned by the find function */
    std::vector<dds::sub::DataReader<dds::core::xtypes::DynamicData>> readers;

    /* Get the list of readers */
    int reader_count = dds::sub::find<
            dds::sub::DataReader<dds::core::xtypes::DynamicData>>(
            subscriber,
            "Square",
            std::back_inserter(readers));

    /* All we need is at least one reader. If there are multiple let’s use the
       first one returned. If no readers are found we create one
     */
    if (reader_count) {
        SquareReader = readers[0];
    } else {
        SquareReader = dds::sub::DataReader<dds::core::xtypes::DynamicData>(
                subscriber,
                Squaretopic);
    }

    reader_count = dds::sub::find<
            dds::sub::DataReader<dds::core::xtypes::DynamicData>>(
            subscriber,
            "Circle",
            std::back_inserter(readers));

    /* All we need is at least one reader. If there are multiple let’s use the
       first one returned. If no readers are found we create one
     */
    if (reader_count) {
        CircleReader = readers[0];
    } else {
        CircleReader = dds::sub::DataReader<dds::core::xtypes::DynamicData>(
                subscriber,
                Circletopic);
    }

    reader_count = dds::sub::find<
            dds::sub::DataReader<dds::core::xtypes::DynamicData>>(
            subscriber,
            "Triangle",
            std::back_inserter(readers));

    /* All we need is at least one reader. If there are multiple let’s use the
       first one returned. If no readers are found we create one
     */
    if (reader_count) {
        TriangleReader = readers[0];
    } else {
        TriangleReader = dds::sub::DataReader<dds::core::xtypes::DynamicData>(
                subscriber,
                Triangletopic);
    }
}


void AShapesSubscriberManager::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    UWorld* World = GetWorld();
    FActorSpawnParameters SpawnParams;
    SpawnParams.bNoFail = TRUE;

    if (SquareReader != dds::core::null) {
        rti::sub::LoanedSamples<dds::core::xtypes::DynamicData> samples =
                SquareReader.select()
                        .state(dds::sub::status::DataState::new_instance())
                        .read();

        /* Process each sample which is valid */
        for (const auto& sample : samples) {
            if (sample->info().valid()) {
                /* Check if there are new instances */
                dds::sub::status::ViewState view_state =
                        sample.info().state().view_state();
                if (view_state == dds::sub::status::ViewState::new_view()) {
                    /* Set the color of the new instance and spawn the
                     * subscriber */
                    FString color(
                            sample->data().value<std::string>("color").c_str());
                    const FTransform SpawnLocAndRotation;
                    AActor* a = World->SpawnActorDeferred<AActor>(
                            SquareSub,
                            SpawnLocAndRotation);
                    AShapeSubDynamic* s = Cast<AShapeSubDynamic>(a);
                    s->Initialize(
                            SquareReader,
                            sample->info().instance_handle(),
                            color);
                    s->FinishSpawning(SpawnLocAndRotation);
                }
            }
        }
    }

    if (CircleReader != dds::core::null) {
        rti::sub::LoanedSamples<dds::core::xtypes::DynamicData> samples =
                CircleReader.select()
                        .state(dds::sub::status::DataState::new_instance())
                        .read();

        /* Process each sample which is valid */
        for (const auto& sample : samples) {
            if (sample->info().valid()) {
                dds::sub::status::ViewState view_state =
                        sample.info().state().view_state();
                if (view_state == dds::sub::status::ViewState::new_view()) {
                    FString color(
                            sample->data().value<std::string>("color").c_str());
                    const FTransform SpawnLocAndRotation;
                    AActor* a = World->SpawnActorDeferred<AActor>(
                            CircleSub,
                            SpawnLocAndRotation);
                    AShapeSubDynamic* s = Cast<AShapeSubDynamic>(a);
                    s->Initialize(
                            CircleReader,
                            sample->info().instance_handle(),
                            color);
                    s->FinishSpawning(SpawnLocAndRotation);
                }
            }
        }
    }

    if (TriangleReader != dds::core::null) {
        rti::sub::LoanedSamples<dds::core::xtypes::DynamicData> samples =
                TriangleReader.select()
                        .state(dds::sub::status::DataState::new_instance())
                        .read();

        /* Process each sample which is valid */
        for (const auto& sample : samples) {
            if (sample->info().valid()) {
                dds::sub::status::ViewState view_state =
                        sample.info().state().view_state();
                if (view_state == dds::sub::status::ViewState::new_view()) {
                    FString color(
                            sample->data().value<std::string>("color").c_str());
                    const FTransform SpawnLocAndRotation;
                    AActor* a = World->SpawnActorDeferred<AActor>(
                            TriangleSub,
                            SpawnLocAndRotation);
                    AShapeSubDynamic* s = Cast<AShapeSubDynamic>(a);
                    s->Initialize(
                            TriangleReader,
                            sample->info().instance_handle(),
                            color);
                    s->FinishSpawning(SpawnLocAndRotation);
                }
            }
        }
    }
}