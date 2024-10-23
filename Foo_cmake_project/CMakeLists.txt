cmake_minimum_required(VERSION 3.5)
project(Foo)

#find_package(Bar 2.0 REQUIRED)

add_library(Foo SHARED Foo.cpp)
target_link_libraries(Foo)

install(TARGETS Foo EXPORT FooTargets
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib
  RUNTIME DESTINATION bin
  INCLUDES DESTINATION include
)

install(EXPORT FooTargets
  FILE FooTargets.cmake
  NAMESPACE Foo::
  DESTINATION lib/cmake/Foo
)

