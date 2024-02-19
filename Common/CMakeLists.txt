cmake_minimum_required(VERSION 3.24)
project(Common)

set(CMAKE_CXX_STANDARD 20)
SET(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCE
        include/GameObject.h
        include/IGameObject.h
        include/IMovable.h
        include/IRotate.h
        include/quaternion.h
        include/quaternion_io.h
        include/quaternion_utils.h

        src/GameObject.cpp
        )

add_library(${PROJECT_NAME} STATIC ${SOURCE})

target_include_directories(${PROJECT_NAME}
        PRIVATE ${CMAKE_SOURCE_DIR}/Common/include
        )

if (MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE
            /W4
            )
else ()
    target_compile_options(${PROJECT_NAME} PRIVATE
            -Wall -Wextra -pedantic -Werror
            )
endif()