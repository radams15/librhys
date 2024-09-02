cmake_minimum_required(VERSION 3.13)
project(rhys VERSION 0.1.0 DESCRIPTION "Rhys' helper library" LANGUAGES C CXX)

include(GNUInstallDirs)

set(CMAKE_C_STANDARD 99)

set(FILES
        src/rhys.c
        include/rhys.h
        include/macros.h
)

if(BUILD_SHARED_LIBS)
    add_library(rhys SHARED ${FILES})
else()
    add_library(rhys STATIC ${FILES})
endif()

set_target_properties(rhys PROPERTIES
        VERSION ${PROJECT_VERSION}
        SOVERSION ${PROJECT_VERSION_MAJOR}
        PUBLIC_HEADER include/rhys.h)

configure_file(rhys.pc.in rhys.pc @ONLY)

target_include_directories(rhys PUBLIC include/)
include_directories(include/)
target_include_directories(rhys PRIVATE src/)

install(TARGETS rhys
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

install(FILES ${CMAKE_BINARY_DIR}/rhys.pc
        DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/pkgconfig)
