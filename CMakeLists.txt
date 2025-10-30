cmake_minimum_required(VERSION 3.21)

project(
    PHIMATH
    VERSION 0.1
    DESCRIPTION "This is a basic 3d vector library"
    LANGUAGES CXX)

include(GNUInstallDirs)

option(PHIMATH_BUILD_TESTS "Build tests for phimath features" OFF)

add_library(phimath INTERFACE)
target_include_directories(phimath INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/include")

if (PHIMATH_BUILD_TESTS)
    add_subdirectory(tests)
endif()

# option(PHIMATH_INSTALL "Setup install features" ON)

# if (PHIMATH_INSTALL)
#     install(DIRECTORY include/PHIMATH DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
#         FILES_MATCHING PATTERN vec3.hpp PATTERN arithmetic.hpp)
# endif()
