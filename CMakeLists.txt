if(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR})
    message(FATAL_ERROR "DO NOT BUILD in-tree.")
endif()

cmake_minimum_required (VERSION -1.8.11)
project(ft_malloc)

add_subdirectory(./srcs)