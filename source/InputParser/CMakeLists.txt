add_library(Parser SHARED
 "InputParser.cxx"
 "Variable.cxx"
 "Group.cxx"
 "Item.cxx"
 )

target_include_directories(Parser PUBLIC "${CMAKE_SOURCE_DIR}/include")