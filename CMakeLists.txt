###############################################################################
###                             CMAKE SETTINGS                              ###
###############################################################################

cmake_minimum_required (
  VERSION
    3.12
)

set (
  CMAKE_ARCHIVE_OUTPUT_DIRECTORY
    ${CMAKE_BINARY_DIR}/lib
)

set (
  CMAKE_LIBRARY_OUTPUT_DIRECTORY
    ${CMAKE_BINARY_DIR}/lib
)

set (
  CMAKE_RUNTIME_OUTPUT_DIRECTORY
    ${CMAKE_BINARY_DIR}/bin
)


###############################################################################
###                              C++ SETTINGS                               ###
###############################################################################

set (
  CMAKE_CXX_STANDARD
    17
)

set (
  CMAKE_CXX_STANDARD_REQUIRED
    ON
)

set (
  CMAKE_CXX_EXTENSIONS
    OFF
)

add_compile_options (
  -Wall
  -Wextra
  -pedantic
)


###############################################################################
###                         PROJECT INITIALIZATION                          ###
###############################################################################

project (
  EasyChat
)

add_subdirectory (
  src
)