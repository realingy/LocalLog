cmake_minimum_required(VERSION 3.5)

project(LogTest)

set( CMAKE_CXX_FLAGS "-std=c++11" )

set(CMAKE_CONFIGRATION_TYPES "Release" CACHE STRING "" FORCE)

# set(LIB_DIR ${PROJECT_SOURCE_DIR}/..)
# set(LIB_DIR ${CMAKE_SOURCE_DIR}/..)
set(LIB_DIR ${CMAKE_SOURCE_DIR})
message("library directory: ", ${LIB_DIR})

# include_directories(${PROJECT_SOURCE_DIR}/llog/include)
include_directories(${LIB_DIR}/llog/include)

add_executable(LogTest "numtest.cpp")

# target_link_libraries(LogTest "${PROJECT_SOURCE_DIR}/llog/lib/llog.lib")
target_link_libraries(LogTest "${LIB_DIR}/llog/Debug/llogd.lib")

# target_link_libraries(LogTest llog)
