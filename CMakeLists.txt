cmake_minimum_required(VERSION 3.15)

project(Tetriminos VERSION 1.0 LANGUAGES CXX)

# C++ Standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

# Set binary directory
# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/build")

include_directories(${CMAKE_SOURCE_DIR}/includes)

# SFML setup
find_package(SFML 2.5 COMPONENTS graphics window system QUIET)

include(FetchContent)
if (NOT SFML_FOUND)
    message(STATUS "SFML not found, fetching SFML from GitHub, manually...")

    FetchContent_Declare(
        sfml
        GIT_REPOSITORY "https://github.com/SFML/SFML.git"
        GIT_TAG 2.6.0
        SOURCE_DIR "${CMAKE_SOURCE_DIR}/_deps/sfml-src"
        UPDATE_DISCONNECTED ON
        QUIET OFF
    )

    # FetchContent_Populate
    FetchContent_MakeAvailable(sfml)
endif()

add_executable(Tetriminos_2D
    src/GameController.cpp
    src/Board.cpp
    src/Renderer.cpp
    src/main.cpp
)

target_link_libraries(Tetriminos_2D PRIVATE sfml-graphics sfml-window sfml-system)

# Include SFML headers automatically
target_include_directories(Tetriminos_2D PRIVATE ${SFML_INCLUDE_DIR})

# Enable warnings and strict compile options in DEBUG mode
if (CMAKE_BUILD_TYPE MATCHES Debug)
    target_compile_options(Tetriminos_2D PRIVATE -Wall -Wextra -Wpedantic)
endif()

# Copying necessary resources to the binary dir.
# Custom commands to copy files to the source directory
add_custom_command(TARGET Tetriminos_2D POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${CMAKE_SOURCE_DIR}/images"
        "${CMAKE_BINARY_DIR}/images"
    COMMENT "Copying resources from the source directory"
)

# Add a custom target to depend on the custom command
add_custom_target(CopyFiles ALL DEPENDS Tetriminos_2D)
