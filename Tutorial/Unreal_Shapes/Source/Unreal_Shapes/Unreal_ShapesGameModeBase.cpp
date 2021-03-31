// Copyright Epic Games, Inc. All Rights Reserved.
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

#include "Unreal_ShapesGameModeBase.h"
#include "ShapesPlayerController.h"

AUnreal_ShapesGameModeBase::AUnreal_ShapesGameModeBase()
{
	PlayerControllerClass = AShapesPlayerController::StaticClass();
}
