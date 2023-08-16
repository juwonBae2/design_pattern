cmake_minimum_required(VERSION 3.12)

project(abstract_factory_pattern)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(${PROJECT_NAME}
    src/abstract_factory_pattern.cpp
    src/main.cpp
)

target_include_directories(${PROJECT_NAME}
  PRIVATE
    include
    ${PROJECT_BINARY_DIR}/include
    ${PROJECT_BINARY_DIR}/src
)

target_link_libraries(${PROJECT_NAME}
    PRIVATE
        spdlog::spdlog
)

set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)
