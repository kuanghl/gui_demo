
cmake_minimum_required(VERSION 2.8...3.30)

project(glfw_imgui)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_WAYLAND OFF CACHE BOOL "" FORCE)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_DEBUG_POSTFIX _d)

# Add glfw dependency
include(FetchContent)
FetchContent_Declare(
  glfw
  URL ${CMAKE_CURRENT_SOURCE_DIR}/glfw-3.4.zip
  PREFIX ${CMAKE_CURRENT_BINARY_DIR}/glfw
  CONFIGURE_COMMAND   ""
  BUILD_COMMAND       ""
)
FetchContent_MakeAvailable(glfw)

# Add include directories for OpenGL headers
include_directories(
${glfw_SOURCE_DIR}/include
${CMAKE_CURRENT_SOURCE_DIR}/imgui/backends
${CMAKE_CURRENT_SOURCE_DIR}/imgui
${CMAKE_CURRENT_SOURCE_DIR}/imgui/misc/cpp
)

# add imgui library
add_library(imgui-static STATIC "${CMAKE_CURRENT_SOURCE_DIR}/imgui/backends/imgui_impl_opengl3.cpp"
                                "${CMAKE_CURRENT_SOURCE_DIR}/imgui/backends/imgui_impl_glfw.cpp"
                                "${CMAKE_CURRENT_SOURCE_DIR}/imgui/misc/cpp/imgui_stdlib.cpp"
                                "${CMAKE_CURRENT_SOURCE_DIR}/imgui/imgui.cpp"
                                "${CMAKE_CURRENT_SOURCE_DIR}/imgui/imgui_demo.cpp"
                                "${CMAKE_CURRENT_SOURCE_DIR}/imgui/imgui_draw.cpp"
                                "${CMAKE_CURRENT_SOURCE_DIR}/imgui/imgui_tables.cpp"
                                "${CMAKE_CURRENT_SOURCE_DIR}/imgui/imgui_widgets.cpp"
)

# Add your source files
set(SOURCES 
    main.cpp
)

# Add executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Link libraries
if (CMAKE_SYSTEM_NAME MATCHES "Linux")  
    # linux
    target_link_libraries(${PROJECT_NAME} PRIVATE glfw imgui-static GL)
elseif (CMAKE_SYSTEM_NAME MATCHES "Windows") 
    # windows
    target_link_libraries(${PROJECT_NAME} PRIVATE glfw imgui-static OpenGL32)
elseif (CMAKE_SYSTEM_NAME MATCHES "Darwin") 
    # macos
    # find_package(OpenGL REQUIRED)  # cmake >= 3.16
    find_library(OPENGL_LIBRARY OpenGL)
    target_link_libraries(${PROJECT_NAME} PRIVATE glfw imgui-static ${OPENGL_LIBRARIES})
endif()