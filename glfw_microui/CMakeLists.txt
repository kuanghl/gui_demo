# 指定CMake编译最低要求版本
cmake_minimum_required(VERSION 2.8...3.5)

project(glfw_microui)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_WAYLAND OFF CACHE BOOL "" FORCE)

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

# 暴露头文件
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/lib)
# Add include directories for OpenGL headers
include_directories(${glfw_SOURCE_DIR}/include)

# 构建执行文件
add_executable(microui          "${CMAKE_CURRENT_SOURCE_DIR}/main.c"
                                "${CMAKE_CURRENT_SOURCE_DIR}/renderer.c"
                                "${CMAKE_CURRENT_SOURCE_DIR}/lib/microui.c")

# 链接库
if (CMAKE_SYSTEM_NAME MATCHES "Linux")  
    # linux
    target_link_libraries(microui glfw GL)
elseif (CMAKE_SYSTEM_NAME MATCHES "Windows") 
    # windows
    target_link_libraries(microui glfw OpenGL32)
elseif (CMAKE_SYSTEM_NAME MATCHES "Darwin") 
    # macos
    # find_package(OpenGL REQUIRED)  # cmake >= 3.16
    find_library(OPENGL_LIBRARY OpenGL)
    target_link_libraries(microui glfw ${OPENGL_LIBRARIES})
endif()

