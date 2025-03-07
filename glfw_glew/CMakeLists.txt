cmake_minimum_required(VERSION 2.8...3.30)

project(glfw_glew)

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

# Add GLEW dependency
FetchContent_Declare(
  glew
  URL ${CMAKE_CURRENT_SOURCE_DIR}/glew-cmake-2.2.0.zip
  PREFIX ${CMAKE_CURRENT_BINARY_DIR}/glew
  CONFIGURE_COMMAND   ""
  BUILD_COMMAND       ""
)
FetchContent_MakeAvailable(glew)

# Add include directories for OpenGL headers
include_directories(
${glfw_SOURCE_DIR}/include
${glew_SOURCE_DIR}/include
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
    target_link_libraries(${PROJECT_NAME} PRIVATE glfw libglew_static GL)
elseif (CMAKE_SYSTEM_NAME MATCHES "Windows") 
    # windows
    target_link_libraries(${PROJECT_NAME} PRIVATE glfw libglew_static OpenGL32)
elseif (CMAKE_SYSTEM_NAME MATCHES "Darwin") 
    # macos
    # find_package(OpenGL REQUIRED)  # cmake >= 3.16
    find_library(OPENGL_LIBRARY OpenGL)
    target_link_libraries(${PROJECT_NAME} PRIVATE glfw libglew_static ${OPENGL_LIBRARIES})
endif()
