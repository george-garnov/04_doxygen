cmake_minimum_required(VERSION 3.2)

if (DEFINED ENV{TRAVIS_BUILD_NUMBER})
    project(test VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})
else()
    project(test VERSION 0.0.1)
endif()

find_package(GTest REQUIRED)

include_directories(${GTEST_INCLUDE_DIR})

add_executable(${PROJECT_NAME} test.cpp)

set_target_properties(
        ${PROJECT_NAME} PROPERTIES
        CXX_STANDARD 14
        CXX_STANDARD_REQUIRED ON
        COMPILE_OPTIONS -Wpedantic -Wall -Wextra
)

target_link_libraries(
  ${PROJECT_NAME}
  ${GTEST_BOTH_LIBRARIES}
  version
  pthread
)

add_test(test ${PROJECT_NAME})

enable_testing()
