cmake_minimum_required(VERSION 3.15)

project(nodec_input LANGUAGES CXX)

add_library(${PROJECT_NAME} INTERFACE)

target_include_directories(
    ${PROJECT_NAME}
    INTERFACE include
)

target_link_libraries(${PROJECT_NAME}
    INTERFACE nodec
)

# Tests
option(NODEC_INPUT_BUILD_TESTS "Enable building tests." OFF)

if(NODEC_INPUT_BUILD_TESTS)
    include(CTest)
    enable_testing()
    add_subdirectory(tests)
endif()