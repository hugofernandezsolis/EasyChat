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