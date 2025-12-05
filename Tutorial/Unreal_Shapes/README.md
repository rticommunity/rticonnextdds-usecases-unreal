![Image](https://www.rti.com/hubfs/RTI_Oct2016/Images/rti-logounit.png)  
 RTI Shapes Demo with Unreal Engine
=====================================

This version of the **RTI Shapes Demo** integration with **Unreal Engine** uses statically compiled datatypes and the Traditional C++ (aka C++98) API of **DDS**.  Unfortunately, the **DDS** Modern C++ API uses RTTI (runtime type checking) which conflicts with how **Unreal Engine** is built and works.

## Example Description

Out-of-the-box, this example **Unreal** application has 3 objects, a red cube, blue sphere and yellow cone that move around in the world automatically at startup staying within an invisible 3-D boundary.  The locations of the objects are published as **DDS** Topics "Square", "Circle" and "Triangle" of type ShapeTypeExtended3D, which is derived from ShapeTypeExtended.  The **RTI Shapes Demo** application can be used to subscribe to the topics and show the positions of the shapes in 2D.

Also, the **Unreal** application subscribes to the same topics and will show 3D objects corresponding to shapes published by  **RTI Shapes Demo**.

### To Run

1.  Assuming that you have **Unreal Engine 5.6.1** (or compatible version) installed.  You should also install **RTI Connext DDS Professional 7.6.0**.  You can get a free download and license from [www.rti.com/get-connext](https://www.rti.com/get-connext).
    
    Install per instructions and make a note of your installation directory.  You will need to create and set the value of an environment variable `NDDSHOME = <install dir>` in your host.

2.  Open [Unreal_Shapes.uproject](./Unreal_Shapes.uproject) in the **Unreal Engine** IDE (aka *Unreal Editor*).

    This may open a dialog window telling you that the *Unreal_Shapes* module is "missing or built with a different engine version" and asks if you "would like to rebuild them now?".  Go ahead and click on *Yes*...when completed successfully, the *Unreal Editor* should open with the project loaded.
    
    Now Generate or Refresh the *Visual Studio Project* using **Tools --> Generate Visual Studio Project** or **Tools --> Refresh Visual Studio Project**

    IT's POSSIBLE THAT THIS DOESN'T WORK...the "rebuild" fails and the *Unreal Editor* doesn't open the project and doesn't even start.  In that case, you will need to regenerate the *Visual Studio* projects manually.  Run:

    `"C:\Program Files\Epic Games\UE_5.6\Engine\Binaries\DotNET\UnrealBuildTool\UnrealBuildTool.exe" -projectfiles -project="<installdir>\rticonnextdds-usecases-unreal\Tutorial\Unreal_Shapes\Unreal_Shapes.uproject" -game -engine`

    replacing `<installdir>` with the location of `rticonnextdds-usecases-unreal`.

3.  Compile the *Unreal_Shapes* C++ components using **Microsoft Visual Studio**.  

    Open **Visual Studio 2022** (or compatible version), either using **Tools --> Open Visual Studio** or directly clicking on the file [Unreal_Shapes.sln](./Unreal_Shapes.sln).
    
    In **Visual Studio**, select the `Development Editor` configuration and Build the solution.

4.  Now open the `Unreal_Shapes.uproject` in the *Unreal Editor* if you weren't able to before, and start the application in the *PIE* (Play-In-Editor) using the "Play" button with the green triangle icon.

    **NOTE:** You may see a Message Log window open showing a warning

        /Game/StarterContent/Architecture/Floor_400x400 Validating asset
        /Game/StarterContent/Architecture/Floor_400x400 Warnings logged while validating asset UpdateValidators request made before RegisterBlueprintValidators. Blueprint validators may be missing!

    This is a known issue with **Unreal Engine** 5.x.

    * **Unreal Engine** has a Blueprint validation system that runs automatically when assets are saved or loaded.

    * The warning indicates that some validation requests happened before the system finished registering all validators.

    This is just a *Warning* and can usually be safely ignored, especially if it's occurring when you first open a project in the *Unreal Editor*.

5.  After starting the project (hitting the green "Play" icon), you can start [**RTI Shape Demo**](https://community.rti.com/static/documentation/connext-dds/current/doc/manuals/connext_dds_professional/tools/shapes_demo/shapes_demo/ShapesTitle.htm) on domain 0.

    Create "Subscribers" for `Square`, `Circle`, and `Triangle` topics in **RTI Shapes Demo**.  You should see values for each topic being displayed.  Those are being published by the running **Unreal** application and correspond to the motion of the 3D version of those objects in the **Unreal** display.

6.  In **RTI Shapes Demo**, you can also create "Publishers" for the different shapes of different colors.  Whatever shapes you create should be received by the **Unreal** application which automatically generates a corresponding 3D object of the color for each instance being published.

## Example Details

The following files were created and added to the project:

* [ShapeType.idl](./Source/Unreal_Shapes/ShapeType.idl)

    File used to define datatypes used by **DDS** *Topics* to send/receive data.

    You may customize this file to add your own datatypes or add/create new **.idl** files with additional datatype definitions.  Please refer to this documentation [Creating User Data Types with IDL](https://community.rti.com/static/documentation/connext-dds/current/doc/manuals/connext_dds_professional/users_manual/users_manual/Creating_User_Data_Types_with_IDL.htm#datatypes_842270378_306763).

    After defining your datatypes, you will use the **RTI Connext** code generator, [***rtiddsgen***](https://community.rti.com/static/documentation/connext-dds/current/doc/manuals/connext_dds_professional/code_generator/users_manual/code_generator/users_manual/UsersManual_Title.htm), to generate the source code that is required by **DDS** to use your datatype.

    To generate code for C++98 (*NOTE: cannot use C++11 due to RTTI conflict with **Unreal** C++*), you should invoke using (on a Windows host):

    `rtiddsgen -ppdisable -replace ShapeType.idl`

    Replace `ShapeType.idl` with your filename(s) if you want to use a different file.

    `rtiddsgen` should generate the following files which need to be added to the **Visual Studio** project to be compiled and linked with your component code:

    * ShapeType.h
    * ShapeTypePlugin.h
    * ShapeTypePlugin.cxx
    * ShapeTypeSupport.h
    * ShapeTypeSupport.cxx

    You should not edit these files, and these files must be regenerated if you modify the associated "ShapeType.idl" file.

* [ShapePub.h](./Source/Unreal_Shapes/ShapePub.h)
    
    [ShapePub.cpp](./Source/Unreal_Shapes/ShapePub.cpp)

    These files define a C++ *Pawn* component that can be configured to publish "Square", "Circle" or "Triangle" topics.  The *Pawn* will automatically bounce around within "invisible" 3D boundaries when created.  The position of the *Pawn* is published with **DDS**.

    To use, you can insert an instance of the *ShapePub* C++ component into a level/map.  Then, you must edit the parameters of the *ShapePub* instance by opening "Window" --> "Outliner", and then selecting the instance in the "Outliner" dialog to configure:

    * Static Mesh : how you want the shape to be rendered
    * Materials : color or texture for the shape surface
    * Connext - Topic Name : "Square", "Circle" or "Triangle"
    * Connext - Color : "BLUE", "RED", "GREEN", "YELLOW", "PURPLE", "ORANGE", "CYAN" or "MAGENTA"
    * Connext - Domain ID : **DDS** domain in which to subscribe to the topic

    You may also want to configure the "Transform" "Scale" to resize the object.

    All of these parameters can be configured in the "Details" dialog when the *ShapePub* component is selected.

    3 C++ components based on *ShapePub* have been pre-inserted in the *Shapes level* map, "RedSquarePub", "BlueCirclePub", and "YellowTrianglePub".
    
    Those components will automatically be created and start publishing their locations on startup.

* [ShapeSubDynamic.h](./Source/Unreal_Shapes/ShapeSubDynamic.h)
    
    [ShapeSubDynamic.cpp](./Source/Unreal_Shapes/ShapeSubDynamic.cpp)

    These files define a C++ *Pawn* component that periodically receives data from **DDS** to move the *Pawn*.  The *Pawn* will be rendered based on the configured "Static Mesh" and "Material" (color).

    To use, for each Shape (e.g. "Square", "Circle", "Triangle"), you first have to create a Blueprint component from the C++ component.
    
    For each Blueprint component created, you have to configure its parameters by double-clicking on the component to open the editor and change:

    * Static Mesh : how you want the shape to be rendered
    * Transform - Scale : resize the shape (0.3 works well)
    * Color : Blue -> Blue, Red -> Red, Green -> Green, etc.

    Out-of-the-box, the *Unreal_Shapes* project has already defined 3 Blueprint components based on *ShapeSubDynamic*:  "SquareDynamicSub", "CircleDynamicSub", and "TriangleDynamicSub".

    The Blueprint components based on *ShapeSubDynamic* are not directly inserted into the World map/level.  Instead, they will be used by a *ShapesSubscriberManager* component to dynamically instantiate *Pawns* of different shapes and colors based on what data is received.

* [ShapesSubscriberManager.h](./Source/Unreal_Shapes/ShapesSubscriberManager.h)
    
    [ShapesSubscriberManager.cpp](./Source/Unreal_Shapes/ShapesSubscriberManager.cpp)

    The *ShapesSubscriberManager* C++ component will subscribe to "Square", "Circle", and "Triangle" topics and when it receives data for a new instance (instance = color) of each topic, it will automatically spawn a *ShapeSubDynamic* component defined for the corresponding shape.

    To use, you can insert an instance of the *ShapeSubscriberManager* C++ component into a level/map.  Then, you must edit the parameters of the *ShapeSubscriberManager* instance by opening "Window" --> "Outliner", and then selecting the instance in the "Outliner" dialog to configure:

    * ShapesSubscriber - Square Sub : Instance of *ShapeSubDynamic* configured to render a square, e.g. *SquareDynamicSub*
    * ShapesSubscriber - Circle Sub : Instance of *ShapeSubDynamic* configured to render a circle, e.g. *CircleDynamicSub*
    * ShapesSubscriber - Triangle Sub : Instance of *ShapeSubDynamic* configured to render a triangle, e.g. *TriangleDynamicSub*
    * Connext - Domain ID : **DDS** domain in which to subscribe to the topic

    This has already been done for you in the *ShapesLevel* map. 

* [ShapeSub.h](./Source/Unreal_Shapes/ShapeSub.h)
    
    [ShapeSub.cpp](./Source/Unreal_Shapes/ShapeSub.cpp)

    This component is not used in the *Unreal_Shapes* project but is provided as an example of a C++ component that can be inserted into a World map to subscribe to data using **DDS**.

    To use, you can insert an instance of the *ShapeSub* component into a map, and then select the instance to configure:

    * Static Mesh : how you want the shape to be rendered
    * Materials : color or texture for the shape surface
    * Connext - Topic Name : "Square", "Circle" or "Triangle"
    * Connext - Color : "BLUE", "RED", "GREEN", "YELLOW", "PURPLE", "ORANGE", "CYAN" or "MAGENTA"
    * Connext - Domain ID : **DDS** domain in which to subscribe to the topic

    Then, if you use **RTI Shapes Demo** to publish the selected shape of the configured color, you should see the object move in the world view.

## Visual Studio Project Modifications

To build and link **RTI Connext** with your own **Unreal** application, you will need to add paths to the **DDS** include files, the required binary libraries for linking as well as some compiler macros (#defines).

You will need to add the following code snippet to your own *.Build.cs* file, for example [Unreal_Shapes.Build.cs](./Source/Unreal_Shapes/Unreal_Shapes.Build.cs).

The following code assume that the environment variable *NDDSHOME* has been set to the path of your **RTI Connext** installation directory when you build the application.

To use the static **RTI Connext** libraries, add the following code:

```    
    public class ConnextExample : ModuleRules
    {
        public ConnextExample(ReadOnlyTargetRules Target) : base(Target)
        {
            <...>

            string nddshome = Environment.GetEnvironmentVariable("NDDSHOME");
            PublicIncludePaths.Add(Path.Combine(nddshome, "include"));
            PublicIncludePaths.Add(Path.Combine(nddshome, "include/ndds"));

            if (Target.Platform == UnrealTargetPlatform.Win64)
            {
                PublicDefinitions.Add("WIN32");
                PublicDefinitions.Add("RTI_STATIC");
                PublicDefinitions.Add("WIN32_LEAN_AND_MEAN");
                PublicAdditionalLibraries.Add(Path.Combine(nddshome, "lib/x64Win64VS2017/nddscppz.lib"));
                PublicAdditionalLibraries.Add(Path.Combine(nddshome, "lib/x64Win64VS2017/nddscz.lib"));
                PublicAdditionalLibraries.Add(Path.Combine(nddshome, "lib/x64Win64VS2017/nddscorez.lib"));
            }
            <...>
```

To use dynamically-linked libraries, insert the following lines instead:

```
            if (Target.Platform == UnrealTargetPlatform.Win64)
            {           {
                PublicDefinitions.Add("WIN32");
                PublicDefinitions.Add("NDDS_DLL_VARIABLE");
                PublicDefinitions.Add("WIN32_LEAN_AND_MEAN");
                PublicAdditionalLibraries.Add(Path.Combine(nddshome, "lib/x64Win64VS2017/nddscpp.lib"));
                PublicAdditionalLibraries.Add(Path.Combine(nddshome, "lib/x64Win64VS2017/nddsc.lib"));
                PublicAdditionalLibraries.Add(Path.Combine(nddshome, "lib/x64Win64VS2017/nddscore.lib"));
                
                RuntimeDependencies.Add(Path.Combine(nddshome, "lib/x64Win64VS2017/nddscpp.dll"));
                RuntimeDependencies.Add(Path.Combine(nddshome, "lib/x64Win64VS2017/nddsc.dll"));
                RuntimeDependencies.Add(Path.Combine(nddshome, "lib/x64Win64VS2017/nddscore.dll"));
                
                //Needed since generated type support code uses exceptions
                bEnableExceptions = true;
            }
```

## Porting Unreal_Shapes

* Changing the version of **RTI Connext DDS**

    If you are using a different version of **RTI Connext DDS Professional**, then you should regenerate the C++ source and header files that support the **DDS** datatypes used by the project as explained in the [Example Details](#example-details) for the file  [ShapeType.idl](./Source/Unreal_Shapes/ShapeType.idl).

    You will need to invoke
    
    `rtiddsgen -ppdisable -replace ShapeType.idl`

    using the *rtiddsgen* distributed with your version of **RTI Connext DDS**.  *rtiddsgen* is usually located in *<ConnextInstallDir>/bin/rtiddsgen*.

* Changing the platform to Linux

    The code of the **DDS**-related components such as *ShapePub*, *ShapeSub*, *ShapeSubDynamic* and *ShapeSubscriberManager* are platform independent and should work both in Windows and Linux.

    In the file, [Unreal_Shapes.Build.cs](./Source/Unreal_Shapes/Unreal_Shapes.Build.cs), there is already code to add the libraries and compiler macros required to build on Linux.
    
    For example, for linking statically, 

            PrivateDefinitions.Add("RTI_LINUX");
            PrivateDefinitions.Add("RTI_UNIX");
            PublicAdditionalLibraries.Add(Path.Combine(nddshome, "lib/x64Linux5Unreal5.2clang15/nddscppz.a"));
            PublicAdditionalLibraries.Add(Path.Combine(nddshome, "lib/x64Linux5Unreal5.2clang15/nddscz.a"));
            PublicAdditionalLibraries.Add(Path.Combine(nddshome, "lib/x64Linux5Unreal5.2clang15/nddscorez.a"));

    For linking dynamically,

            PublicAdditionalLibraries.Add(Path.Combine(nddshome, "lib/x64Linux5Unreal5.2clang15/nddscpp.so"));
            PublicAdditionalLibraries.Add(Path.Combine(nddshome, "lib/x64Linux5Unreal5.2clang15/nddsc.so"));
            PublicAdditionalLibraries.Add(Path.Combine(nddshome, "lib/x64Linux5Unreal5.2clang15/nddscore.so"));
            RuntimeDependencies.Add(Path.Combine(nddshome, "lib/x64Linux5Unreal5.2clang15/nddscpp.so"));
            RuntimeDependencies.Add(Path.Combine(nddshome, "lib/x64Linux5Unreal5.2clang15/nddsc.so"));
            RuntimeDependencies.Add(Path.Combine(nddshome, "lib/x64Linux5Unreal5.2clang15/nddscore.so"));

            // Needed since generated type support code uses exceptions
            bEnableExceptions = true; 

    You will have to make sure that your *Unreal Engine* project is enabled to build Linux applications (cross-compiled from Windows or natively on Linux).  Please consult the *Unreal Engine* documentation on how to do this.  The example project, *Unreal_Shapes*, is only setup to compile for Windows.

    **Note:  This code and project has not been tested and verified to build for Linux.  While the code should compile, there may be issues during linking that
      can be resolved by adding the compiler/linker flags "-stdlib=libc++",  "-fno-rtti", and "-m64".  You may also need to add the following libraries "-ldl -lm -lpthread -lrt".**

* Changing the version of **Unreal Engine**

    If you are using a different version of **Unreal Engine**, you should consult **Unreal** documentation on how to update your project to work with a version of **Unreal Engine** newer than 5.6.1.  To port to an older version of **Unreal Engine**, you should just manually create a new project with your version's *Editor* and then add the C++ source and header files, the ".xml" QoS file to the project.  And then add the required compiler macros, include paths, and libraries for **RTI Connext DDS** to the file "*\<project\>.Build.cs*" of your project.


