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

#pragma once
#pragma warning(disable : 4668)
#pragma warning(disable : 4530)

#pragma once

#include "ndds/ndds_cpp.h"
#include "ShapeType.h"
#include "ShapeTypePlugin.h"
#include "ShapeTypeSupport.h"

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "ShapeSubDynamic.generated.h"

UCLASS()
class UNREAL_SHAPES_API AShapeSubDynamic : public APawn {
    GENERATED_BODY()

public:
    /* Mesh component*/
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "MeshComponent")
    UStaticMeshComponent* StaticMesh;

    /* Colors */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Color")
    UMaterial* Purple;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Color")
    UMaterial* Blue;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Color")
    UMaterial* Red;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Color")
    UMaterial* Green;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Color")
    UMaterial* Yellow;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Color")
    UMaterial* Cyan;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Color")
    UMaterial* Magenta;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Color")
    UMaterial* Orange;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Color")
    UMaterial* Default;

public:
    // Sets default values for this pawn's properties
    AShapeSubDynamic();

    // Called every frame
    virtual void Tick(float DeltaTime) override;

    void Initialize(
        ShapeTypeExtended3DDataReader* Reader,
        DDS_InstanceHandle_t Instance,
        FString myColor);

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;
    virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

private:
    ShapeTypeExtended3DDataReader* Reader = NULL;
    DDS_InstanceHandle_t Instance = DDS_HANDLE_NIL;
};
