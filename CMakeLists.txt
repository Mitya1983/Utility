cmake_minimum_required(VERSION 3.17)

project(Utility LANGUAGES CXX DESCRIPTION "C++ Heplers")
include(CustomFunctions.cmake)

set_project_properties()

prepare_source_files(SRC_FILES)

add_library(${PROJECT_NAME} STATIC ${SRC_FILES})

set_target_properties(${PROJECT_NAME} PROPERTIES VERSION 1.0)
set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME "Utility")

install(TARGETS ${PROJECT_NAME}
        CONFIGURATIONS ${CMAKE_BUILD_TYPE}
        DESTINATION ${CMAKE_BUILD_TYPE}/lib)
install(DIRECTORY ${CMAKE_SOURCE_DIR}/inc DESTINATION ${CMAKE_BUILD_TYPE})