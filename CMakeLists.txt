cmake_minimum_required (VERSION 3.5)

project(zmrEditor)

# 设置版本号码
set (PROJECT_VERSION_MAJOR 0)
set (PROJECT_VERSION_MINOR 0)
set (PROJECT_VERSION_PATCH 0)

# 设置一个是否启用调试
option (DEB
    "Use Debug mode" ON)

# 加入一个配置头文件，用于处理 CMake 对源码的设置
configure_file (
  "${PROJECT_SOURCE_DIR}/config.h.in"
  "${PROJECT_BINARY_DIR}/config.h"
  )

aux_source_directory(. SRCS)
include_directories(.)

add_executable(
    "zmrEditor${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH}_out" 
    ${SRCS}
    )


