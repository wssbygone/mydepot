cmake_minimum_required(VERSION 3.10)
project(example)

set(CMAKE_CXX_STANDARD 17)

SET(ENABLE_TEST OFF)

include_directories(
  ~/workspace/aiplorer/third_party/linux/glog_0.3.5/include
  ~/workspace/aiplorer/third_party/linux/gflags_2.2.2/include
  ~/workspace/aiplorer/third_party/linux/gtest_1.8.1/include
  ./
)

LINK_DIRECTORIES(
  ~/workspace/aiplorer/third_party/linux/glog_0.3.5/lib
  ~/workspace/aiplorer/third_party/linux/gflags_2.2.2/lib
  ~/workspace/aiplorer/third_party/linux/gtest_1.8.1/lib
)

aux_source_directory(src SRC)

add_library(${PROJECT_NAME}_core SHARED
    ${SRC}
)

target_link_libraries(${PROJECT_NAME}_core
    glog
)

set(LIBS
    ${PROJECT_NAME}_core
    glog
)

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} ${LIBS})

if (ENABLE_TEST)
    add_subdirectory(test)
endif()
