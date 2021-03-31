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

#include "ShapePub.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "ShapesPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class UNREAL_SHAPES_API AShapesPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Shape Publisher")
		TSubclassOf<class AShapePub> SquarePub;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Shape Publisher")
		TSubclassOf<class AShapePub> CirclePub;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Shape Publisher")
		TSubclassOf<class AShapePub> TrianglePub;

	/* Domain ID */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Connext")
		int32 DomainID = 0;

private:
	AActor* Publisher = NULL;


protected:
	virtual void SetupInputComponent() override;
	bool ToggleSquarePublisher(FString color);
	void HandleKey();
};
