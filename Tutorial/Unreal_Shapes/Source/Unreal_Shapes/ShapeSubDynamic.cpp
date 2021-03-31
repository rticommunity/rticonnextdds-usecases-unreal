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

#include "ShapeSubDynamic.h"

// Sets default values
AShapeSubDynamic::AShapeSubDynamic()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CustomStaticMesh"));
	RootComponent = StaticMesh;
}

// Called when the game starts or when spawned
void AShapeSubDynamic::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AShapeSubDynamic::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

    /* Only read if the reader has been initialized */
    if (Reader != dds::core::null)
    {
        rti::sub::LoanedSamples<dds::core::xtypes::DynamicData> samples =
            Reader.select().instance(Instance).take();

        /* Process each sample which is valid */
        for (const auto& sample : samples)
        {
            if (sample->info().valid())
            {
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
            bool die = false;
            /* Get the instance state */
            const dds::sub::status::InstanceState& state =
                sample.info().state().instance_state();
            if (state ==
                dds::sub::status::InstanceState::not_alive_disposed())
            {
                die = true;
            }
            if (state ==
                dds::sub::status::InstanceState::not_alive_no_writers())
            {
                die = true;
            }
            if (state ==
                dds::sub::status::InstanceState::not_alive_mask())
            {
                die = true;
            }
            if (die)
            {
                Destroy();
                Reader = dds::core::null;
                Instance = dds::core::null;
            }
        }
    }

}

// Called to bind functionality to input
void AShapeSubDynamic::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AShapeSubDynamic::Initialize(
	dds::sub::DataReader<dds::core::xtypes::DynamicData> myReader,
	dds::core::InstanceHandle myInstance,
	FString myColor)
{
	Reader = myReader;
	Instance = myInstance;

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

