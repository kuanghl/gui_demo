cmake_minimum_required(VERSION 3.16)

project(example LANGUAGES C CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")

include(FetchContent)
# set(WEBVIEW_BUILD_DOCS 1)
FetchContent_Declare(
    webview
    # GIT_REPOSITORY https://github.com/webview/webview
    # GIT_TAG 0.12.0
    URL ${CMAKE_CURRENT_SOURCE_DIR}/webview-master.zip
    # PREFIX ${CMAKE_CURRENT_BINARY_DIR}/webview-master
    )
FetchContent_MakeAvailable(webview)

find_package(Threads REQUIRED)

set(COPYRIGHT "Copyright [year], Your Name")
set(VENDOR "Your Name")
set(DESCRIPTION "Example app made with webview")

if(CMAKE_SYSTEM_NAME STREQUAL "Darwin")
    include(resources/macos/resources.cmake)
elseif(CMAKE_SYSTEM_NAME STREQUAL "Windows")
    include(resources/windows/resources.cmake)
endif()

add_executable(webview_example_basic_c MACOSX_BUNDLE WIN32)
target_sources(webview_example_basic_c PRIVATE basic.c)
target_link_libraries(webview_example_basic_c PRIVATE webview::core_static)

add_executable(webview_example_basic_cc MACOSX_BUNDLE WIN32)
target_sources(webview_example_basic_cc PRIVATE basic.cc)
target_link_libraries(webview_example_basic_cc PRIVATE webview::core)

add_executable(webview_example_bind_c MACOSX_BUNDLE WIN32)
target_sources(webview_example_bind_c PRIVATE bind.c)
target_link_libraries(webview_example_bind_c PRIVATE webview::core_static Threads::Threads)

if(MSVC)
    # Disable some warnings when using MSVC
    target_compile_definitions(webview_example_bind_c PRIVATE _CRT_SECURE_NO_WARNINGS)
endif()

add_executable(webview_example_bind_cc MACOSX_BUNDLE WIN32)
target_sources(webview_example_bind_cc PRIVATE bind.cc)
target_link_libraries(webview_example_bind_cc PRIVATE webview::core Threads::Threads)
