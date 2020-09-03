cmake_minimum_required(VERSION 3.5)

project(LogTest)

set( CMAKE_CXX_FLAGS "-std=c++11" )

set(CMAKE_CONFIGRATION_TYPES "Release" CACHE STRING "" FORCE)

# set(OpenCV_DIR $ENV{OPENCV_DIR})
# message(${OpenCV_DIR})
# find_package(OpenCV REQUIRED)

# include_directories(${OpenCV_DIR}/install/include)
# include_directories(${OpenCV_DIR}/install/include/opencv)
# include_directories(${OpenCV_DIR}/install/include/opencv2)

# aux_source_directory(. DIR_SRCS)

add_executable(LogTest "numtest.cpp")
target_link_libraries (LogTest )
