cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
project(recipe-02 LANGUAGES CXX)

add_executable(hello-world hello.cpp)

if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
  target_compile_definitions(hello-world PRIVATE "IS_LINUX")
endif()
if(CMAKE_SYSTEM_NAME STREQUAL "Darwin")
  target_compile_definitions(hello-world PRIVATE "IS_MACOS")
endif()
if(CMAKE_SYSTEM_NAME STREQUAL "Windows")
  target_compile_definitions(hello-world PRIVATE "IS_WINDOWS")
endif()


