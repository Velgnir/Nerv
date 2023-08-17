cmake_minimum_required(VERSION 3.9)

# It is used as a project's main executable name.
set(PROJECT_NAME Nerv)
project(${PROJECT_NAME} CXX)

set(CMAKE_CXX_STANDARD 20)

##########################################################
# User configurable options of the template
##########################################################
# Note: symbols like WARNINGS_AS_ERRORS in configuration are intentionally variables
# and not CMake options --using options creates too much problem for students.

#! It is a good practice to set "WARNINGS_AS_ERRORS" ON,
set(WARNINGS_AS_ERRORS ON)

#! Always use PVS Studio while developing.
set(ENABLE_PVS_STUDIO ON)

#! Select appropriate sanitizers.
#  Definitely enable sanitizers while developing.
#  Disable it for the production builds and before submitting for grading.
#  Only one of Memory (MSAN), Address (ASAN), or Thread (TSan)
#  sanitizers is applicable at the time -- the first defined.

#! UndefinedBehaviorSanitizer (UBSan)
#  Info: https://clang.llvm.org/docs/UndefinedBehaviorSanitizer.html
set(ENABLE_UBSan ON)
#! AddressSanitizer -- detects use after free or after scope exit,
#  memory overflows and leaks.
#  Info: https://github.com/google/sanitizers/wiki/AddressSanitizer
set(ENABLE_ASAN ON)
#! ThreadSanitizer -- detects data races.
set(ENABLE_TSan OFF)
#! MemorySanitizer detects uninitialized memory reads
#  Info: https://github.com/google/sanitizers/wiki/MemorySanitizer
set(ENABLE_MSAN OFF)


#! Be default -- build release version if not specified otherwise.
if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif ()

# Set output directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../bin)

# Warnings as errors should be imported here -- do not move this line
include(cmake/defaults/CompilerWarnings.cmake)

##########################################################
# Project files, packages, libraries and so on
##########################################################

set(CMAKE_AUTOMOC ON)
# Project source compilation
add_executable(${PROJECT_NAME} src/main.cpp
        src/buttoncustommenu.cpp
        includes/mainwindow.cpp
        src/CustomScrollArea.cpp
        src/fileinlist.cpp
        src/filecontroller.cpp
        )

#! Put path to your project headers
target_include_directories(${PROJECT_NAME} PRIVATE includes)

# Add external packages
find_package(Boost 1.71.0 COMPONENTS program_options REQUIRED)
include_directories(${Boost_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} Boost::program_options)

# Find and include Qt5
find_package(Qt5 REQUIRED COMPONENTS Widgets)

target_link_libraries(${PROJECT_NAME} Qt5::Widgets)

##########################################################
# Fixed CMakeLists.txt part
##########################################################

# Define ALL_TARGETS variable to use in PVS and Sanitizers
set(ALL_TARGETS ${PROJECT_NAME})

# Include CMake setup
include(cmake/config.cmake)
