cmake_minimum_required(VERSION 3.12)

project(visitor_pattern)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

file(GLOB_RECURSE SOURCES "src/*.cpp")

add_executable(${PROJECT_NAME}
    # src/visitor_pattern.cpp
    src/main.cpp
)
target_include_directories(${PROJECT_NAME}
  PUBLIC
    include
    ${PROJECT_BINARY_DIR}/include
  PRIVATE
    ${PROJECT_BINARY_DIR}/src
)
target_link_libraries(${PROJECT_NAME}
    PRIVATE
        spdlog::spdlog
)

set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)

