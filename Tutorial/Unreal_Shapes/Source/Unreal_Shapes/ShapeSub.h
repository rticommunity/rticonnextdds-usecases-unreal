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

#pragma once
#pragma warning(disable : 4668)
#pragma warning(disable : 4530)

#include "ndds/ndds_cpp.h"
#include "ShapeType.h"
#include "ShapeTypePlugin.h"
#include "ShapeTypeSupport.h"

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "ShapeSub.generated.h"

UCLASS()
class UNREAL_SHAPES_API AShapeSub : public APawn {
    GENERATED_BODY()

public:
    /* Mesh component */
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "MeshComponent")
    UStaticMeshComponent* StaticMesh;

    /* Topic Name */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Connext")
    FString TopicName = FString("Square");

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Connext")
    FString Color = FString("BLUE");

    /* Domain ID */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Connext")
    int32 DomainID = 0;

public:
    // Sets default values for this pawn's properties
    AShapeSub();
    // Called every frame
    virtual void Tick(float DeltaTime) override;

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;
    virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

private:
    FString TYPE_NAME = FString("ShapeTypeExtended3D");
    DDSDomainParticipant *participant = NULL;
    DDSSubscriber *subscriber = NULL;
    ShapeTypeExtended3DDataReader *reader = NULL;
};
