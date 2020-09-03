cmake_minimum_required(VERSION 3.5)

set( CMAKE_CXX_FLAGS "-std=c++11" )

set(CMAKE_CONFIGRATION_TYPES "Release" CACHE STRING "" FORCE)

# set(OpenCV_DIR $ENV{OPENCV_DIR})
# find_package(OpenCV REQUIRED)

# 包含目录
# include_directories(${OpenCV_DIR}/install/include)
# include_directories(${OpenCV_DIR}/install/include/opencv)
# include_directories(${OpenCV_DIR}/install/include/opencv2)

# 库的安装路径
SET(CMAKE_INSTALL_PREFIX output)

set(HEADER "logger.h" "logstream.h" "logcommon.h")

FILE(GLOB DIR_HEAD *.h)
# message("heads: ", ${DIR_HEAD})
aux_source_directory(. DIR_SRCS)

# 设置库的类型(SHARED)和名字
add_library(locallog SHARED ${DIR_SRCS} ${DIR_HEAD})

# 设置头文件的安装路径为../output下的include
INSTALL(FILES ${HEADER} DESTINATION include)
# 设置库文件的安装路径为../output下的lib
# INSTALL(TARGETS locallog LIBRARY DESTINATION lib)

set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

link_directories(${PROJECT_SOURCE_DIR}/lib) #链接库存放目录
# add_executable( ${DIR_SRCS})
# target_link_libraries (${EXENAME} ${OpenCV_LIBS})
