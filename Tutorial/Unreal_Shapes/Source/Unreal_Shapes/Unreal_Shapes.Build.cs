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

using System;
using System.IO;
using UnrealBuildTool;

public class Unreal_Shapes : ModuleRules
{
    public Unreal_Shapes(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore" });

        PrivateDependencyModuleNames.AddRange(new string[] { });

        //		bUseRTTI = true;
        //		bEnableExceptions = true;

        string nddshome = Environment.GetEnvironmentVariable("NDDSHOME");

        PublicIncludePaths.Add(Path.Combine(nddshome, "include"));
        PublicIncludePaths.Add(Path.Combine(nddshome, "include/ndds"));

        PublicDefinitions.Add("RTI_WIN32");
        PublicDefinitions.Add("RTI_STATIC");
        PublicDefinitions.Add("WIN32_LEAN_AND_MEAN");

        PublicAdditionalLibraries.Add(Path.Combine(nddshome, "lib/x64Win64VS2017/nddscppz.lib"));
        PublicAdditionalLibraries.Add(Path.Combine(nddshome, "lib/x64Win64VS2017/nddscz.lib"));
        PublicAdditionalLibraries.Add(Path.Combine(nddshome, "lib/x64Win64VS2017/nddscorez.lib"));

        //    PrivateDefinitions.Add("RTI_LINUX");
        //    PrivateDefinitions.Add("RTI_UNIX");
        //    PublicAdditionalLibraries.Add(Path.Combine(nddshome, "lib/x64Linux5Unreal5.2clang15/nddscppz.a"));
        //    PublicAdditionalLibraries.Add(Path.Combine(nddshome, "lib/x64Linux5Unreal5.2clang15/nddscz.a"));
        //    PublicAdditionalLibraries.Add(Path.Combine(nddshome, "lib/x64Linux5Unreal5.2clang15/nddscorez.a"));
    
    }
}
