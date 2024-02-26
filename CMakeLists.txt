cmake_minimum_required(VERSION 3.20)
project(Arh_1)

set(CMAKE_CXX_STANDARD 20)


SET(BIN_DIR "${CMAKE_SOURCE_DIR}/bin/${CMAKE_BUILD_TYPE}")

add_subdirectory("${CMAKE_SOURCE_DIR}/googletest"
        "googletest")
#add_subdirectory("Test")
add_subdirectory("Main")
#add_subdirectory("Server")
add_subdirectory("Common")


include(CPack)

enable_testing()
add_test(Tests ${CMAKE_SOURCE_DIR}/Tests)