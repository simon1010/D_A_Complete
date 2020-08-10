cmake_minimum_required (VERSION 3.5)

# set project anme
project (Galileo)

# setup version numbers
set(VERSION_MAJOR 1)
set(VERSION_MINOR 0)
set(VERSION_PATCH 0)

set(CMAKE_CXX_STANDARD 14)
# add galileo header path
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/galileo/common)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/third_party/QCustomPlot)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/third_party/aquila)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/third_party/IIR)

# add the subdirectories
add_subdirectory(src/galileo)
add_subdirectory(third_party/QCustomPlot)
add_subdirectory(third_party/aquila)
add_subdirectory(third_party/IIR)