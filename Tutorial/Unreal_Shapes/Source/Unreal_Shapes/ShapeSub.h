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
#pragma warning(disable:4668)
#pragma warning(disable:4530)

#include <dds/dds.hpp>

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "ShapeSub.generated.h"

UCLASS()
class UNREAL_SHAPES_API AShapeSub : public APawn
{
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

private:
	FString QOS_URL = FString("Connext/Unreal_Shapes.xml");
	FString TYPE_NAME = FString("ShapeTypeExtended3D");
	dds::sub::DataReader<dds::core::xtypes::DynamicData> reader = dds::core::null;


public:
	// Sets default values for this pawn's properties
	AShapeSub();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
