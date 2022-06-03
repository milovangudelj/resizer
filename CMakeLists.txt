cmake_minimum_required(VERSION 3.15 FATAL_ERROR)
project(resizer VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

find_package(OpenCV REQUIRED)
message(STATUS "Found OpenCV v${OpenCV_VERSION}")

add_library(resizer STATIC 
	src/resizer.cc
)
add_library(cxxopts INTERFACE)
add_library(cxxopts::cxxopts ALIAS cxxopts)

include_directories(${OpenCV_INCLUDE_DIRS})
include_directories(include)
include_directories(/opt/cxxopts/include)

add_executable(rr src/targets/rr.cc)

target_link_libraries(resizer PUBLIC ${OpenCV_LIBS})
target_link_libraries(rr PRIVATE resizer)