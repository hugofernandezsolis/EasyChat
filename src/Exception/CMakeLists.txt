###############################################################################
###                            COMPONENT SOURCES                            ###
###############################################################################

set (
  COMPONENT_NAME
    Exception
)

set (
  SOURCES
    ${CMAKE_CURRENT_LIST_DIR}/src/${COMPONENT_NAME}.cpp
)

set (
  HEADERS
    ${CMAKE_CURRENT_LIST_DIR}/include/${COMPONENT_NAME}.h
)

set (
  TESTS
    ${CMAKE_CURRENT_LIST_DIR}/tests/Exception_Tests.cpp
)

###############################################################################
###                              SUBDIRECTORIES                             ###
###############################################################################

add_library (
  ${COMPONENT_NAME}
    SHARED
      ${SOURCES}
      ${HEADERS}
)

add_executable (
  ${COMPONENT_NAME}_Tests
    ${TESTS}
)

# Set include directories
target_include_directories (
  ${COMPONENT_NAME}
    PUBLIC
      ${CMAKE_CURRENT_LIST_DIR}/include
)


###############################################################################
###                               GTEST LIBRARY                             ###
###############################################################################

enable_testing()

find_package (
  GTest
   REQUIRED
)

target_link_libraries(
  ${COMPONENT_NAME}_Tests
    GTest::gtest_main
)

include_directories (
  ${GTEST_INCLUDE_DIRS}
)