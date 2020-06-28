cmake_minimum_required(VERSION 3.11)
project(Intent_Recognizer)

set(GTEST_VERSION 1.8.0 CACHE STRING "Google test version")


# GTest

include(FetchContent)

FetchContent_Declare(googletest
GIT_REPOSITORY https://github.com/google/googletest.git
GIT_TAG release-${GTEST_VERSION})

FetchContent_GetProperties(googletest)

if(NOT googletest_POPULATED)
  FetchContent_Populate(googletest)
  add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})
endif()

SET(CMAKE_CXX_FLAGS -pthread)

# Unit Tests

# Add test cpp file
add_executable(runUnitTests intent_recognizer_test.cpp ../src/intent_recognizer.h)

# Include directories
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# Link test executable against gtest & gtest_main
target_link_libraries(runUnitTests gtest
                                   gtest_main)
enable_testing()

add_test(NAME google_test
	COMMAND $<TARGET_FILE:runUnitTests>
	)
