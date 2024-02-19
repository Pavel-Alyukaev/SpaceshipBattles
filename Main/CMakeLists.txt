cmake_minimum_required(VERSION 3.24)
project(Game)

set(CMAKE_CXX_STANDARD 20)

set(SRC
        include/stdafx.h
        src/main.cpp
        )
add_executable(Game ${SRC})
target_precompile_headers(Game PRIVATE include/stdafx.h)
set_target_properties( ${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${BIN_DIR} )

target_include_directories(${PROJECT_NAME}
        #PRIVATE ${CMAKE_SOURCE_DIR}/Server/include
        PRIVATE ${CMAKE_SOURCE_DIR}/Common/include
        )

target_link_libraries(${PROJECT_NAME}
        #PRIVATE Server
        PRIVATE Common
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