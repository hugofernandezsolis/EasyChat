###############################################################################
###                         LIBRARY CONFIGURATIONS                          ###
###############################################################################

add_executable (
  ${PROJECT_NAME}
)

target_sources (
  ${PROJECT_NAME}
    PRIVATE
      ${PROJECT_NAME}.cpp
)


###############################################################################
###                               COMPONENTS                                ###
###############################################################################

set (
  COMPONENTS
    Error
    Socket
)

foreach(COMPONENT IN LISTS COMPONENTS)
  target_include_directories (
    ${PROJECT_NAME}
      PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/${COMPONENT}/include
  )

  file (
    GLOB
      SOURCES
        CONFIGURE_DEPENDS
          "${CMAKE_CURRENT_LIST_DIR}/${COMPONENT}/src/*.cpp"
  )

  foreach(SRC IN LISTS SOURCES)
    target_sources (
      ${PROJECT_NAME}
        PRIVATE
          ${SRC}
    )
  endforeach()
endforeach()


###############################################################################
###                               GTEST LIBRARY                             ###
###############################################################################

enable_testing()

find_package (
  GTest
   REQUIRED
)

include_directories (
  ${GTEST_INCLUDE_DIRS}
)

foreach(COMPONENT IN LISTS COMPONENTS)

  add_executable (
    ${COMPONENT}_Tests
  )

  target_include_directories (
    ${COMPONENT}_Tests
      PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/${COMPONENT}/include
  )

  file (
    GLOB
      TESTS
        CONFIGURE_DEPENDS
          "${CMAKE_CURRENT_LIST_DIR}/${COMPONENT}/tests/*.cpp"
  )

  foreach(TEST IN LISTS TESTS)
    target_sources (
      ${COMPONENT}_Tests
        PRIVATE
          ${TEST}
    )
  endforeach()

  target_link_libraries(
    ${COMPONENT}_Tests
    gtest  
    gtest_main
  )

  include(GoogleTest)
  gtest_discover_tests(${COMPONENT}_Tests)
endforeach()