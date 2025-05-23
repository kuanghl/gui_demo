cmake_minimum_required(VERSION 3.14 FATAL_ERROR)

project(wx_cmake_fetchcontent_template LANGUAGES CXX)

include(FetchContent)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

message(STATUS "Fetching wxWidgets...")

FetchContent_Declare(
   wxWidgets
   QUIET
#    GIT_REPOSITORY https://github.com/wxWidgets/wxWidgets.git
#    GIT_SHALLOW ON
   URL ${CMAKE_CURRENT_SOURCE_DIR}/../wxWidgets-3.2.8
#   PREFIX ${CMAKE_CURRENT_BINARY_DIR}/wxWidgets
)
set(wxBUILD_SHARED OFF CACHE BOOL "Build shared or static libraries")
# set(wxBUILD_TESTS OFF CACHE STRING "Build tests CONSOLE_ONLY, ALL or OFF")
# set(wxBUILD_SAMPLES OFF CACHE STRING "Build samples SOME, ALL or OFF")
# set(wxBUILD_DEMOS OFF CACHE BOOL "Build demos Build demo applications")
# set(wxBUILD_MONOLITHIC ON CACHE BOOL "Build a single library")
FetchContent_MakeAvailable(wxWidgets)


set(SRCS main.cpp)

if(APPLE)
    # create bundle on apple compiles
    add_executable(main MACOSX_BUNDLE ${SRCS})

    # Set a custom plist file for the app bundle - needed for Mac OS Retina display
    set_target_properties(main PROPERTIES MACOSX_BUNDLE_INFO_PLIST ${CMAKE_CURRENT_SOURCE_DIR}/Info.plist)
else()
    # the WIN32 is needed for Windows in order for it to look for WinMain
    # instead of the main function. This is ignored on other systems,
    # so it works on all platforms
    add_executable(main WIN32 ${SRCS} main.exe.manifest)
endif()

target_link_libraries(main PRIVATE wxcore wxnet)
target_include_directories(main PRIVATE ${wxWidgets_SOURCE_DIR}/include)
