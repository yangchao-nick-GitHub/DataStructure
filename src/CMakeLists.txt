cmake_minimum_required(VERSION 3.16)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} SRC_LIST)
add_executable(demo ${SRC_LIST})

