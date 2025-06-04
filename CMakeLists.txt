cmake_minimum_required(VERSION 3.20)
project(HelloCMake)

# 设置vcpkg toolchain文件
set(CMAKE_TOOLCHAIN_FILE "./vcpkg/scripts/buildsystems/vcpkg.cmake"
  CACHE STRING "Vcpkg toolchain file")

# 查找包
find_package(fmt CONFIG REQUIRED)
find_package(spdlog CONFIG REQUIRED)

# 创建可执行文件
add_executable(main main.cpp)

# 链接库
target_link_libraries(main PRIVATE fmt::fmt spdlog::spdlog)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET main PROPERTY CXX_STANDARD 23)
endif()
