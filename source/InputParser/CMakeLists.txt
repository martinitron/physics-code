add_library(Parser STATIC
 "InputParser.cxx"
 "Variable.cxx"
 "Group.cxx"
 "Item.cxx"
 )

target_include_directories(Parser PUBLIC "${CMAKE_SOURCE_DIR}/include")