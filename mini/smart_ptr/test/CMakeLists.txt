cmake_minimum_required(VERSION 3.10)
project(test_example)

aux_source_directory(. TEST_SRC)
include_directories(include)
add_executable(${PROJECT_NAME} ${TEST_SRC})
set(LIBS
    example_core
    glog
    pthread 
    gtest
    gtest_main
)
target_link_libraries(${PROJECT_NAME} ${LIBS})
