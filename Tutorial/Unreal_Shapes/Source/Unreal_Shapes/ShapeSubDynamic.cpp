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

#include "ShapeSubDynamic.h"

#include "BaseUtilities.h"

// Sets default values
AShapeSubDynamic::AShapeSubDynamic()
{
    // Set this pawn to call Tick() every frame.  You can turn this off to
    // improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

    StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(
            TEXT("CustomStaticMesh"));
    RootComponent = StaticMesh;
}

// Called when the game starts or when spawned
void AShapeSubDynamic::BeginPlay()
{
    Super::BeginPlay();

    // Initialization
    BeginGameSession();
}

// Called every frame
void AShapeSubDynamic::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    /* Only read if the reader has been initialized */
    if (Reader != NULL) {
        ShapeTypeExtended3DSeq shapeSeq;
        DDS_SampleInfoSeq infoSeq;

        Reader->take_instance(shapeSeq, infoSeq, DDS_LENGTH_UNLIMITED, Instance);
        
        /* Process each sample which is valid */
        for (int i = 0; i < shapeSeq.length(); ++i) {
            if (infoSeq[i].valid_data) {
                /* Read the values we are interested (X and Y) from
                   the dynamic data */
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
            /* Get the instance state */
            if (infoSeq[i].instance_state != DDS_ALIVE_INSTANCE_STATE) {
                Destroy();
                Reader = NULL;
            }
        }

        Reader->return_loan(shapeSeq, infoSeq);
    }
}

void AShapeSubDynamic::Initialize(
        ShapeTypeExtended3DDataReader* myReader,
        DDS_InstanceHandle_t myInstance,
        FString myColor)
{
    Reader = myReader;
    Instance = myInstance;

    if (myColor == "PURPLE")
        StaticMesh->SetMaterial(0, Purple);
    else if (myColor == "BLUE")
        StaticMesh->SetMaterial(0, Blue);
    else if (myColor == "RED")
        StaticMesh->SetMaterial(0, Red);
    else if (myColor == "GREEN")
        StaticMesh->SetMaterial(0, Green);
    else if (myColor == "YELLOW")
        StaticMesh->SetMaterial(0, Yellow);
    else if (myColor == "CYAN")
        StaticMesh->SetMaterial(0, Cyan);
    else if (myColor == "MAGENTA")
        StaticMesh->SetMaterial(0, Magenta);
    else if (myColor == "ORANGE")
        StaticMesh->SetMaterial(0, Orange);
    else
        StaticMesh->SetMaterial(0, Default);
}

void AShapeSubDynamic::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
    Super::EndPlay(EndPlayReason);

    Reader = NULL;

    Destroy();
    GEngine->ForceGarbageCollection(true);
}
