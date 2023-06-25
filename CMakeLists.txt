cmake_minimum_required(VERSION 3.10)
project(exam_2023_ii)


add_executable(sc main.cpp src/num_vector.cpp src/options.cpp inc/options.h src/processing.cpp inc/processing.h)

target_compile_features(sc PRIVATE cxx_std_20)

# TODO enable compiler warnings
target_compile_options(sc PRIVATE -Wall -Wextra -pedantic -Werror)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=address")
set(CMAKE_LINKER_FLAGS_DEBUG "${CMAKE_LINKER_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=address")

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/spacy.txt ${CMAKE_CURRENT_BINARY_DIR}/spacy.txt COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/liney.txt ${CMAKE_CURRENT_BINARY_DIR}/liney.txt COPYONLY)