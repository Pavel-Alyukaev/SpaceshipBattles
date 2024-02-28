cmake_minimum_required(VERSION 3.20)
project(Common)

set(CMAKE_CXX_STANDARD 20)
SET(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCE
        include/SpaceSheep.h
        include/IGameObject.h
        include/ICommand.h
        include/IMovable.h
        include/quaternion.h
        include/quaternion_io.h
        include/quaternion_utils.h
        include/Teleportation.h
        include/RotateObjXY.h

        src/SpaceSheep.cpp
        src/Teleportation.cpp
        src/RotateObjXY.cpp
        src/MoveObj.cpp
        src/GameObjectBase.cpp )

add_library(${PROJECT_NAME} STATIC ${SOURCE})

target_include_directories(${PROJECT_NAME}
        PRIVATE ${CMAKE_SOURCE_DIR}/Common/include
        )

if (MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE
            /W4 /WX-
            )
else ()
    target_compile_options(${PROJECT_NAME} PRIVATE
            -Wall -Wextra -pedantic -Werror
            )
endif()
