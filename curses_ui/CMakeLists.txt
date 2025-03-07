cmake_minimum_required(VERSION 2.8...3.5)

project(curses_ui)

# set(BUILD_SUBTARGET_NAME "vt")
option(BUILD_SUBTARGET_NAME "Build the SUBDIRECTORIES: vt/x11/fb/ncurses/wincon/wingui" vt)

# demo
message(STATUS "build name: ${BUILD_SUBTARGET_NAME}")
if(BUILD_SUBTARGET_NAME STREQUAL "vt")
    add_subdirectory(vt)
elseif(BUILD_SUBTARGET_NAME STREQUAL "x11")
    add_subdirectory(x11)
elseif(BUILD_SUBTARGET_NAME STREQUAL "fb")
    add_subdirectory(fb)
elseif(BUILD_SUBTARGET_NAME STREQUAL "ncurses")
    add_subdirectory(ncurses)
elseif(BUILD_SUBTARGET_NAME STREQUAL "wincon")
    add_subdirectory(wincon)
elseif(BUILD_SUBTARGET_NAME STREQUAL "wingui")
    add_subdirectory(wingui)
else()
    message(STATUS "Not Support ${BUILD_SUBTARGET_NAME}")
endif()