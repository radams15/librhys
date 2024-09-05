cmake_minimum_required(VERSION 3.13)
project(rhys VERSION 0.1.0 DESCRIPTION "Rhys' helper library" LANGUAGES C CXX)

include(GNUInstallDirs)
include(Versioning.cmake)

set(PROJECT_VERSION ${LIBRHYS_VERSION} CACHE STATIC "" FORCE)

message(WARNING ${LIBRHYS_VERSION})

set(CMAKE_C_STANDARD 99)

set(FILES
        src/rhys.c
        include/rhys/rhys.h
        include/rhys/macros.h
        src/logger.c
        include/rhys/logger.h
)

option(BUILD_LOGGER "Build the logger module" Yes)

if(BUILD_SHARED_LIBS)
    add_library(rhys SHARED ${FILES})
else()
    add_library(rhys STATIC ${FILES})
endif()

if(BUILD_LOGGER)
    target_compile_definitions(rhys PUBLIC RHYS_BUILD_LOGGER Yes)
endif()

add_executable(rhys_test test/test.c)
target_link_libraries(rhys_test rhys)

set_target_properties(rhys PROPERTIES
        VERSION ${PROJECT_VERSION}
        PUBLIC_HEADER include/rhys/rhys.h)

configure_file(rhys.pc.in rhys.pc @ONLY)

target_include_directories(rhys PRIVATE include/ include/rhys)
include_directories(include/)
target_include_directories(rhys PRIVATE src/)

install(TARGETS rhys
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

install(FILES ${CMAKE_BINARY_DIR}/rhys.pc
        DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/pkgconfig)
