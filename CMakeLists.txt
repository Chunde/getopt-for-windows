cmake_minimum_required(VERSION 3.23.2)
project(getopt_for_windows)
set(TARGET_NAME ${PROJECT_NAME})

add_library(${PROJECT_NAME} SHARED getopt.c)
add_library(${PROJECT_NAME}_static STATIC getopt.c)

set(LIB_DIR "lib/${PROJECT_NAME}")
set(TARGETS_EXPORT_NAME "${PROJECT_NAME}Targets")

set(INCLUDE_INSTALL_DIR include/ )
set(LIB_INSTALL_DIR lib/ )

# install(TARGETS ${PROJECT_NAME} ${PROJECT_NAME}_static DESTINATION ${LIB_DIR})

install(
  TARGETS ${PROJECT_NAME} 
  DESTINATION lib
  COMPONENT libraries
  )

install(
  TARGETS ${PROJECT_NAME}_static 
  DESTINATION lib
  COMPONENT libraries
  )

install(FILES getopt.h
  DESTINATION include
  COMPONENT headers
)

include(CMakePackageConfigHelpers)
configure_package_config_file(
    "cmake/Config.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake"
    INSTALL_DESTINATION "${CMAKE_INSTALL_PREFIX}"
    PATH_VARS INCLUDE_INSTALL_DIR LIB_INSTALL_DIR
)

install(
    FILES "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake"
    DESTINATION "${CMAKE_INSTALL_PREFIX}"
)
