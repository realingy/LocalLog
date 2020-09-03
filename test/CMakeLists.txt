cmake_minimum_required(VERSION 3.5)

project(LogTest)

set( CMAKE_CXX_FLAGS "-std=c++11" )

set(CMAKE_CONFIGRATION_TYPES "Release" CACHE STRING "" FORCE)

include_directories(${PROJECT_SOURCE_DIR}/llog/include)

add_executable(LogTest "numtest.cpp")

link_directories(${PROJECT_SOURCE_DIR}/llog/lib)

target_link_libraries(LogTest llog)
