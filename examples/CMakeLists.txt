cmake_minimum_required(VERSION 3.0.2)
project(examples LANGUAGES C)

add_subdirectory(.. build)

if(CMAKE_C_COMPILER_ID STREQUAL "Clang")
  add_compile_options(-Weverything)
elseif(CMAKE_C_COMPILER_ID STREQUAL "GNU")
  add_compile_options(-Wall -Wextra -pedantic)
endif()

add_executable(demo demo.c)

get_property(
  EXAMPLES
  DIRECTORY .
  PROPERTY BUILDSYSTEM_TARGETS)

foreach(TARGET ${EXAMPLES})
  target_link_libraries(${TARGET} assert-algebraic)
  set_target_properties(${TARGET} PROPERTIES C_STANDARD 99 C_STANDARD_REQUIRED
                                                           ON)
endforeach()
