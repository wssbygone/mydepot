# rm -rf build && cmake -S . -B build -DBUILD_SHARED_LIBS=ON && make -C build && ./build/CPP
# https://cloud.tencent.com/developer/article/2312928?pos=comment

cmake_minimum_required(VERSION 3.22)
project(CPP)
 
set(CMAKE_CXX_STANDARD 17)
 
add_library(A libA/a.cc)    # default BUILD_SHARED_LIBS=OFF
target_include_directories(A PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/includeA)
 
add_library(B SHARED libB/b.cc)
target_link_libraries(B PRIVATE A)
target_include_directories(B PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/includeB)
 
add_executable(CPP main.cc ${CMAKE_CURRENT_SOURCE_DIR}/includeA/a.h)
target_link_libraries(CPP B)
target_include_directories(CPP PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/includeA)
