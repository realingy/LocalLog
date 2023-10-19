cmake_minimum_required(VERSION 3.5)

project(LogTest)

set( CMAKE_CXX_FLAGS "-std=c++11" )

set(CMAKE_CONFIGRATION_TYPES "Release" CACHE STRING "" FORCE)

# set(LIB_DIR ${PROJECT_SOURCE_DIR}/..)
set(LIB_DIR ${CMAKE_SOURCE_DIR})
message("library directory: " ${LIB_DIR})

# include_directories(${PROJECT_SOURCE_DIR}/llog/include)
include_directories(${LIB_DIR}/llog/include)

add_executable(LogTest "numtest.cpp")

if(CMAKE_BUILD_TYPE AND (CMAKE_BUILD_TYPE STREQUAL "Debug"))
    message("Debug mode:${CMAKE_C_FLAGS_DEBUG}")
    set(LLOG_ROOT_DIR ${CMAKE_SOURCE_DIR}/llog)
    set(LLOG_LIBRARIES_DIR ${LLOG_ROOT_DIR}/lib/Debug)
    message("Lib Dir: ${LLOG_LIBRARIES_DIR}")
    find_library(LLOG_LIBRARIES NAMES llogd PATHS ${LLOG_LIBRARIES_DIR})
    target_link_libraries(LogTest ${LLOG_LIBRARIES})
elseif(CMAKE_BUILD_TYPE AND (CMAKE_BUILD_TYPE STREQUAL "Release"))
    message("Release mode:${CMAKE_C_FLAGS_RELEASE}")
    set(LLOG_ROOT_DIR ${CMAKE_SOURCE_DIR}/llog)
    set(LLOG_LIBRARIES_DIR ${LLOG_ROOT_DIR}/lib/Release)
    message("Lib Dir: ${LLOG_LIBRARIES_DIR}")
    find_library(LLOG_LIBRARIES NAMES llog PATHS ${LLOG_LIBRARIES_DIR})
    target_link_libraries(LogTest ${LLOG_LIBRARIES})
else()
    message("else:${CMAKE_BUILD_TYPE}")
    message("else:${CMAKE_C_FLAGS_RELEASE}")
endif()

# target_link_libraries(LogTest llog)
