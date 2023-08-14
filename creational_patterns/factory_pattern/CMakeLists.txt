cmake_minimum_required(VERSION 3.12)

project(factory_pattern)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Add executable
add_executable(${PROJECT_NAME}
    src/factory_pattern.cpp
    src/main.cpp
)

# Add include directories
target_include_directories(${PROJECT_NAME}
  PUBLIC
    include
    ${PROJECT_BINARY_DIR}/include
  PRIVATE
    ${PROJECT_BINARY_DIR}/src
)

# Link necessary libraries
target_link_libraries(${PROJECT_NAME}
    PRIVATE
        spdlog::spdlog
)

# Set output directory
set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)
