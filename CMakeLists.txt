cmake_minimum_required(VERSION 3.15 FATAL_ERROR)
set(VERSION 0.1.1)
project(resizer VERSION ${VERSION} LANGUAGES CXX)

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
find_package(OpenCV REQUIRED core imgcodecs imgproc)
set(OpenCV_LIB_DIR "${OpenCV_DIR}/lib" CACHE PATH "Directory containing static OpenCV libraries")
set(OpenCV_BIN_DIR "${OpenCV_DIR}/bin" CACHE PATH "Directory containing dynamic OpenCV libraries")
link_directories(${OpenCV_LIB_DIR})
include_directories(${OpenCV_INCLUDE_DIRS})
message(STATUS "OpenCV include directories: ${OpenCV_DIR}")
target_link_libraries(resizer PUBLIC ${OpenCV_LIBS})

# cxxopts - Lightweight library for parsing options - https://github.com/jarro2783/cxxopts
add_subdirectory(extern/cxxopts)
target_include_directories(${TARGET_NAME} PUBLIC cxxopts)
target_link_libraries(${TARGET_NAME} PUBLIC cxxopts)

# CPack stuff
set(CPACK_GENERATOR "RPM")
set(CPACK_RPM_USER_BINARY_SPECFILE "${CMAKE_CURRENT_SOURCE_DIR}/release/Resizer.spec")

set(CPACK_PACKAGE_NAME "Resizer")
set(CPACK_PACKAGE_SUMMARY "A small image resizing utility.")
set(CPACK_PACKAGE_DESCRIPTION_FILE "${CMAKE_CURRENT_SOURCE_DIR}/release/DESCRIPTION.txt")
set(CPACK_PACKAGE_VERSION ${VERSION})
set(CPACK_PACKAGE_RELEASE 1)
set(CPACK_PACKAGE_LICENSE "MIT")
set(CPACK_PACKAGE_GROUP "Applications/Productivity/Other")
set(CPACK_PACKAGE_CONTACT "Milovan Gudelj <i.like.martians@gmail.com>")
set(CPACK_PACKAGE_VENDOR "i.like.martians Inc.")
set(CMAKE_PROJECT_HOMEPAGE_URL "https://github.com/milovangudelj/resizer")

set(CPACK_PACKAGE_BUILD_REQUIRES "cmake >= 3.15")

set(CPACK_PACKAGE_FILE_NAME "${CPACK_PACKAGE_NAME}-${CPACK_PACKAGE_VERSION}-${CPACK_PACKAGE_RELEASE}.${CMAKE_SYSTEM_PROCESSOR}")
set(CPACK_INSTALL_PREFIX "/usr/local/bin")
set(CPACK_PACKAGING_INSTALL_PREFIX ${CMAKE_INSTALL_PREFIX})

set(CPACK_RPM_CHANGELOG_FILE "${CMAKE_CURRENT_SOURCE_DIR}/release/CHANGELOG.txt")
file(READ ${CPACK_RPM_CHANGELOG_FILE} CPACK_RPM_SPEC_CHANGELOG)

# install(DIRECTORY "${OpenCV_BIN_DIR}/" DESTINATION bin)
install(TARGETS rr RUNTIME DESTINATION bin)

include(CPack)