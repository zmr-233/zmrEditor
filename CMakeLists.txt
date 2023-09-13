cmake_minimum_required (VERSION 3.5)

project(zmrEditor)

# 设置版本号码
set (PROJECT_VERSION_MAJOR 0)
set (PROJECT_VERSION_MINOR 0)
set (PROJECT_VERSION_PATCH 0)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

# 设置一个是否启用调试
option (DEB
    "Use Debug mode" ON)

# 加入一个配置头文件，用于处理 CMake 对源码的设置
configure_file (
  "${PROJECT_SOURCE_DIR}/config.h.in"
  "${PROJECT_BINARY_DIR}/src/config.h"
  )

include_directories(./src)
aux_source_directory(./src SRCS)
set (TARGET "zmrEditor${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH}_out")
add_executable(${TARGET} ${SRCS})

find_package(X11 REQUIRED)
target_link_libraries(${TARGET} PRIVATE ${X11_LIBRARIES})
target_link_libraries(${TARGET} PRIVATE sfml-graphics)
target_compile_features(${TARGET} PRIVATE cxx_std_17)    

if(WIN32)
    add_custom_command(
        TARGET CMakeSFMLProject
        COMMENT "Copy OpenAL DLL"
        PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<BOOL:${ARCH_64BITS}>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:CMakeSFMLProject>
        VERBATIM)
endif()




