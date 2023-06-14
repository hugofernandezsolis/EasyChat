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

###############################################################################
###                              SUBDIRECTORIES                             ###
###############################################################################

add_library (
  ${COMPONENT_NAME}
    SHARED
      ${SOURCES}
      ${HEADERS}
)

# Set include directories
target_include_directories (
  ${COMPONENT_NAME}
    PUBLIC
      ${CMAKE_CURRENT_LIST_DIR}/include
)
