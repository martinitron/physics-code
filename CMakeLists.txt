cmake_minimum_required(VERSION "3.17.0")

project("physics_code")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory("source")

add_executable("physics_bin" "main.cxx")
target_link_libraries(physics_bin Parser)

target_include_directories("physics_bin" PUBLIC "${CMAKE_SOURCE_DIR}/include")