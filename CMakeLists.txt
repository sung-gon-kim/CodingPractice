cmake_minimum_required(VERSION 3.5.0 FATAL_ERROR)

project(CodingPractice VERSION 1.0.0 LANGUAGES CXX)

# Load CMake modules
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/scripts)
include(CMakeUtils)

set_cxx_standard(14)

enable_static_analysis(NO_IWYU)
enable_testing()
enable_test_coverage()

add_all_subdirectories()
