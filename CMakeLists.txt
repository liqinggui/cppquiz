cmake_minimum_required(VERSION 3.10)

project(cppquiz)

set(CMAKE_CXX_STANDARD 23)

find_program(CLANG_FORMAT_EXE clang-format)

if (NOT CLANG_FORMAT_EXE)
    message(FATAL_ERROR "clang-format not found")
endif()

file(GLOB_RECURSE ALL_SOURCE_FILES
    "*.cpp"
    "*.h"
    "*.cc"
    "*.hh"
)

add_custom_target(format-check
    COMMAND ${CLANG_FORMAT_EXE} -style=file -output-replacements-xml ${ALL_SOURCE_FILES}
    COMMENT "Checking code style with clang-format"
    VERBATIM
)

add_custom_target(format
    COMMAND ${CLANG_FORMAT_EXE} -style=file -i ${ALL_SOURCE_FILES}
    COMMENT "Formatting code with clang-format"
    VERBATIM
)

add_subdirectory(src)