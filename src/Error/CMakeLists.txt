###############################################################################
###                            COMPONENT SOURCES                            ###
###############################################################################

set (
  COMPONENT_NAME
    Error
)

set (
  SOURCES
    ${CMAKE_CURRENT_LIST_DIR}/src/${COMPONENT_NAME}.cpp
)

set (
  TESTS
    ${CMAKE_CURRENT_LIST_DIR}/tests/Error_Tests.cpp
)

###############################################################################
###                              SUBDIRECTORIES                             ###
###############################################################################

add_library (
  ${COMPONENT_NAME}
    SHARED
      ${SOURCES}
)

add_executable (
  ${COMPONENT_NAME}_Tests
    ${TESTS}
    ${SOURCES}
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

target_include_directories (
  ${COMPONENT_NAME}_Tests
    PUBLIC
      ${CMAKE_CURRENT_LIST_DIR}/include
)

include_directories (
  ${GTEST_INCLUDE_DIRS}
)