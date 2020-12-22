add_library(Meshes STATIC
  "Meshes.cxx"
  "GridPoints.cxx"
  "Connectivity.cxx")

target_include_directories(Meshes PUBLIC "${CMAKE_SOURCE_DIR}/include")