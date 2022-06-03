cmake_minimum_required(VERSION 3.15 FATAL_ERROR)
project(resizer VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

find_package(OpenCV REQUIRED)
message(STATUS "Found OpenCV v${OpenCV_VERSION}")

include_directories(${OpenCV_INCLUDE_DIRS})
include_directories(include)

add_executable(resizer src/targets/resizer.cc)

target_link_libraries(resizer ${OpenCV_LIBS})