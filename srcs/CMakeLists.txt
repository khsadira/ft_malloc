include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../includes)
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

AUX_SOURCE_DIRECTORY(${CMAKE_CURRENT_SOURCE_DIR} source)
add_executable(ft_malloc ${source})