project(MachineLib)

set(SOURCE_FILES
        pch.h
        IMachineSystem.h
        MachineSystemFactory.cpp MachineSystemFactory.h
        MachineStandin.cpp MachineStandin.h
        Polygon.cpp Polygon.h
        MachineDialog.cpp MachineDialog.h include/machine-api.h
        MachineSystemStandin.cpp
        MachineSystemStandin.h
        Const.cpp
        Const.h
        MachineSystem.cpp
        MachineSystem.h
        Machine.cpp
        Machine.h
        MachineCFactory.cpp
        MachineCFactory.h
        Component.cpp
        Component.h
        Shape.cpp
        Shape.h
        Motor.cpp
        Motor.h
        MotionSource.cpp
        MotionSource.h
        MotionSink.cpp
        MotionSink.h
        Pulley.cpp
        Pulley.h
        SnowBlower.cpp
        SnowBlower.h
        SnowFlakes.cpp
        SnowFlakes.h
        Machine2Factory.cpp
        Machine2Factory.h
)

# Removed:
# Motor.cpp Motor.h Pulley.cpp Pulley.h

find_package(wxWidgets COMPONENTS core base xrc html xml REQUIRED)
include(${wxWidgets_USE_FILE})

add_library(${PROJECT_NAME} STATIC ${SOURCE_FILES})
