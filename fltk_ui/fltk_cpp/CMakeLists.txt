cmake_minimum_required(VERSION 2.8...3.30)

project(hello)

include(FetchContent)

set(FLTK_BUILD_TEST OFF CACHE BOOL " " FORCE)
if(UNIX AND NOT APPLE) 
    set(OPTION_USE_PANGO ON CACHE BOOL " " FORCE)
endif()

FetchContent_Declare(FLTK
    QUIET
    # GIT_REPOSITORY      https://github.com/fltk/fltk
    # GIT_TAG             v1.4.3
    URL ${CMAKE_CURRENT_SOURCE_DIR}/fltk-release-1.4.3.zip
    # PREFIX ${CMAKE_CURRENT_BINARY_DIR}/fltk-release-1.4.3
)

FetchContent_MakeAvailable(FLTK)

add_executable(hello WIN32 MACOSX_BUNDLE ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)
target_include_directories(hello PRIVATE ${fltk_BINARY_DIR} ${fltk_SOURCE_DIR})
target_link_libraries(hello PRIVATE fltk) # + fltk_gl fltk_images fltk_png fltk_jpeg fltk_z 

if(APPLE)
    target_link_libraries(hello PRIVATE "-framework Cocoa") # needed for macOS
endif()