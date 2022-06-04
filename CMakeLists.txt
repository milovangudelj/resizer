cmake_minimum_required(VERSION 3.15 FATAL_ERROR)
project(resizer VERSION 0.1.0 LANGUAGES CXX)

set(TARGET_NAME rr) # Target name
set(CMAKE_CXX_STANDARD 17) # C++ Standard

# Internal library
add_library(resizer STATIC 
	src/resizer.cc
)

# Internal include directory
include_directories(include)

# Main executable
add_executable(${TARGET_NAME} src/targets/rr.cc)

# Link internal library to main executable
target_link_libraries(${TARGET_NAME} PRIVATE resizer)

# OpenCV
find_package(OpenCV REQUIRED)

if(${OpenCV_VERSION})
	message(STATUS "Found OpenCV v${OpenCV_VERSION}")
else()
	message(STATUS "Couldn't find OpenCV")
endif()

include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries(resizer PUBLIC ${OpenCV_LIBS})

# cxxopts - Lightweight library for parsing options - https://github.com/jarro2783/cxxopts
add_subdirectory(extern/cxxopts)
target_include_directories(${TARGET_NAME} PUBLIC cxxopts)
target_link_libraries(${TARGET_NAME} PUBLIC cxxopts)