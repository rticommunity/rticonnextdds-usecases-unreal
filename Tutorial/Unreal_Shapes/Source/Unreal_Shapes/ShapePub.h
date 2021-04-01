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
#include "GameFramework/Pawn.h"
#include "ShapePub.generated.h"

UCLASS()
class UNREAL_SHAPES_API AShapePub : public APawn {
    GENERATED_BODY()

public:
    /* Mesh component */
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "MeshComponent")
    UStaticMeshComponent* StaticMesh;

    /* Topic Name */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Connext")
    FString TopicName = FString("Square");

    /* Color */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, category = "Connext")
    FString Color = FString("BLUE");

    /* Colors */
    UPROPERTY(EditAnywhere, Category = "Color")
    UMaterial* Purple;
    UPROPERTY(EditAnywhere, Category = "Color")
    UMaterial* Blue;
    UPROPERTY(EditAnywhere, Category = "Color")
    UMaterial* Red;
    UPROPERTY(EditAnywhere, Category = "Color")
    UMaterial* Green;
    UPROPERTY(EditAnywhere, Category = "Color")
    UMaterial* Yellow;
    UPROPERTY(EditAnywhere, Category = "Color")
    UMaterial* Cyan;
    UPROPERTY(EditAnywhere, Category = "Color")
    UMaterial* Magenta;
    UPROPERTY(EditAnywhere, Category = "Color")
    UMaterial* Orange;
    UPROPERTY(EditAnywhere, Category = "Color")
    UMaterial* Default;


    /* Domain ID */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Connext")
    int32 DomainID = 0;

private:
    FString QOS_URL = FString("Connext/Unreal_Shapes.xml");
    FString TYPE_NAME = FString("ShapeTypeExtended3D");
    dds::pub::DataWriter<dds::core::xtypes::DynamicData> writer =
            dds::core::null;
    FVector MinBox = FVector(0.0f);
    FVector MaxBox = FVector(250.0f, 260.0f, 270.0f);
    FVector Direction = FVector(0.0f);
    dds::core::xtypes::DynamicData* sample = dds::core::null;


public:
    // Sets default values for this pawn's properties
    AShapePub();

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

public:
    // Called every frame
    virtual void Tick(float DeltaTime) override;

    // Called to bind functionality to input
    virtual void SetupPlayerInputComponent(
            class UInputComponent* PlayerInputComponent) override;

    void Initialize(int32_t myDomainId, FString myColor);
    void StopPublish();
};
