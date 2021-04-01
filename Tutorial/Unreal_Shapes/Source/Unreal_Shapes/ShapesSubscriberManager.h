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

#include <dds/dds.hpp>

#include "CoreMinimal.h"
#include "GameFramework/Info.h"
#include "ShapesSubscriberManager.generated.h"

/**
 *
 */
UCLASS()
class UNREAL_SHAPES_API AShapesSubscriberManager : public AInfo {
    GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Shape Subscriber")
    TSubclassOf<class AShapeSubDynamic> SquareSub;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Shape Subscriber")
    TSubclassOf<class AShapeSubDynamic> CircleSub;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Shape Subscriber")
    TSubclassOf<class AShapeSubDynamic> TriangleSub;

    /* Domain ID */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Connext")
    int32 DomainID = 0;

private:
    FString QOS_URL = FString("Connext/Unreal_Shapes.xml");
    FString TYPE_NAME = FString("ShapeTypeExtended3D");
    dds::sub::DataReader<dds::core::xtypes::DynamicData> SquareReader =
            dds::core::null;
    dds::sub::DataReader<dds::core::xtypes::DynamicData> CircleReader =
            dds::core::null;
    dds::sub::DataReader<dds::core::xtypes::DynamicData> TriangleReader =
            dds::core::null;

public:
    AShapesSubscriberManager();

protected:
    virtual void BeginPlay() override;
    virtual void Tick(float DeltaTime) override;
};