# config
set(CMAKE_TOOLCHAIN_FILE "./tools/vcpkg/scripts/buildsystems/vcpkg.cmake")
cmake_minimum_required(VERSION 3.20)
project(database-access)

# output
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# 3rd party
find_package(fmt     CONFIG REQUIRED)
find_package(libpqxx CONFIG REQUIRED)
find_package(doctest CONFIG REQUIRED)

# include
add_subdirectory(src/)
add_subdirectory(tests/)
