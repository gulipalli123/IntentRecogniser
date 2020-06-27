cmake_minimum_required(VERSION 3.10)

project (test LANGUAGES CXX)

if(NOT CMAKE_BUILD_TYPE)
	set(CMAKE_BUILD_TYPE Release CACHE STRING "Build type" FORCE)
endif()

message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")

list(APPEND flags "-fPIC" "-Wall")
if(NOT WIN32)
	list(APPEND flags "-Wextra" "-Wpedantic")
endif()


add_executable(intentRecognizer intent_recognizer.cpp)

target_compile_options(intentRecognizer
PRIVATE
${flags}
) 

set_target_properties(intentRecognizer
PROPERTIES
CXX_STANDARD 11
CXX_EXTENSIONS OFF
CXX_STANDARD_REQUIRED ON
)
target_compile_features(intentRecognizer PRIVATE cxx_lambda_init_captures)
