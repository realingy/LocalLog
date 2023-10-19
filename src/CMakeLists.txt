cmake_minimum_required(VERSION 3.5)

set( CMAKE_CXX_FLAGS "-std=c++11" )

set(CMAKE_CONFIGRATION_TYPES "Release" CACHE STRING "" FORCE)

SET(CMAKE_INSTALL_PREFIX llog)

FILE(GLOB DIR_HEAD *.h)
aux_source_directory(. DIR_SRCS)

# debug后缀
set(CMAKE_DEBUG_POSTFIX "d")

add_library(llog SHARED ${DIR_SRCS} ${DIR_HEAD})

add_library(llog_static STATIC ${DIR_SRCS} ${DIR_HEAD})
# 指定静态库的输出名称
set_target_properties(llog_static PROPERTIES OUTPUT_NAME "llog")
# 使动态库和静态库同时存在
set_target_properties(llog PROPERTIES CLEAN_DIRECT_OUTPUT 1)
set_target_properties(llog_static PROPERTIES CLEAN_DIRECT_OUTPUT 1)

# 设置头文件的安装路径为../output下的include
# INSTALL(FILES ${HEADER} DESTINATION ${PROJECT_SOURCE_DIR}/include)
# 设置库文件的安装路径为../output下的lib
# INSTALL(TARGETS llog LIBRARY DESTINATION ${PROJECT_SOURCE_DIR}/llog)

set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/llog/lib)

# 头文件输出
set(HEADER "logger.h" "logstream.h" "logcommon.h")
FILE(COPY ${HEADER} DESTINATION "${CMAKE_SOURCE_DIR}/llog/include")

# 将动态库与动态库同时安装到lib目录中
install (TARGETS llog llog_static DESTINATION ${PROJECT_SOURCE_DIR}/llog/bin)
