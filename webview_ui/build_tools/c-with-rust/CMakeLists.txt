cmake_minimum_required(VERSION 3.18)

project(c-with-rust C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# update to contain more rust flags
set(C_WITH_RUST_RUST_FLAGS "")      
set(C_WITH_RUST_CARGO_TARGET "")     # target folder name

# extra link libraries
set(PLATFORM_C_LINK_LIBS "")
set(CARGO_EXTRA_ENVS "")

# check platform set PLATFORM_C_LINK_LIBS and CARGO_EXTRA_ENVS
message(STATUS "system-name " ${CMAKE_SYSTEM_NAME})
if (CMAKE_SYSTEM_NAME STREQUAL "Linux")
  list(APPEND PLATFORM_C_LINK_LIBS ${CMAKE_DL_LIBS})
elseif (CMAKE_SYSTEM_NAME STREQUAL "Emscripten")
  set(C_WITH_RUST_CARGO_TARGET wasm32-unknown-emscripten)
elseif (CMAKE_SYSTEM_NAME STREQUAL "iOS")
  if (CMAKE_OSX_SYSROOT MATCHES ".*iPhoneSimulator\\.platform.*")
    if(CMAKE_OSX_ARCHITECTURES MATCHES "x86_64")
      set(C_WITH_RUST_CARGO_TARGET x86_64-apple-ios)
    else ()
      set(C_WITH_RUST_CARGO_TARGET aarch64-apple-ios-sim)
    endif ()
  else ()
    set(C_WITH_RUST_CARGO_TARGET aarch64-apple-ios)
  endif ()
  # add extra dependency needed for rust tokenizer in iOS
  find_library(FOUNDATION_LIB Foundation)
  find_library(SECURITY_LIB Security)
  list(APPEND PLATFORM_C_LINK_LIBS ${FOUNDATION_LIB} ${SECURITY_LIB})
elseif (CMAKE_SYSTEM_NAME STREQUAL "Darwin")
  if (CMAKE_SYSTEM_PROCESSOR STREQUAL "arm64")
    set(C_WITH_RUST_CARGO_TARGET aarch64-apple-darwin)
  endif()
elseif (CMAKE_SYSTEM_NAME STREQUAL "Android")
  if (ANDROID_ABI STREQUAL "arm64-v8a")
    set(C_WITH_RUST_CARGO_TARGET aarch64-linux-android)
  elseif (ANDROID_ABI STREQUAL "armeabi-v7a")
    set(C_WITH_RUST_CARGO_TARGET armv7-linux-androideabi)
  elseif (ANDROID_ABI STREQUAL "x86_64")
    set(C_WITH_RUST_CARGO_TARGET x86_64-linux-android)
  elseif (ANDROID_ABI STREQUAL "x86")
    set(C_WITH_RUST_CARGO_TARGET i686-linux-android)
  endif()
  set(CARGO_EXTRA_ENVS
    AR_${C_WITH_RUST_CARGO_TARGET}=${ANDROID_TOOLCHAIN_ROOT}/bin/llvm-ar
    CC_${C_WITH_RUST_CARGO_TARGET}=${ANDROID_TOOLCHAIN_ROOT}/bin/${C_WITH_RUST_CARGO_TARGET}${ANDROID_NATIVE_API_LEVEL}-clang
    CXX_${C_WITH_RUST_CARGO_TARGET}=${ANDROID_TOOLCHAIN_ROOT}/bin/${C_WITH_RUST_CARGO_TARGET}${ANDROID_NATIVE_API_LEVEL}-clang++
  )
elseif (CMAKE_SYSTEM_NAME STREQUAL "Windows")
  set(C_WITH_RUST_CARGO_TARGET x86_64-pc-windows-msvc)
  list(APPEND PLATFORM_C_LINK_LIBS
    ntdll wsock32 ws2_32 Bcrypt
    iphlpapi userenv psapi
  )
endif()

# build rust cargo parameters
# 1. build rust flags, such as debug/release
set(C_WITH_RUST_CARGO_FLAGS "")                                 
set(C_WITH_RUST_CARGO_TARGET_DIR ${CMAKE_CURRENT_BINARY_DIR})
set(C_WITH_RUST_CARGO_BINARY_DIR ${CMAKE_CURRENT_BINARY_DIR})

if (NOT C_WITH_RUST_CARGO_TARGET STREQUAL "")
    list(APPEND C_WITH_RUST_CARGO_FLAGS --target ${C_WITH_RUST_CARGO_TARGET})
    set(C_WITH_RUST_CARGO_BINARY_DIR
        "${C_WITH_RUST_CARGO_BINARY_DIR}/${C_WITH_RUST_CARGO_TARGET}")
endif()

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(C_WITH_RUST_CARGO_BINARY_DIR "${C_WITH_RUST_CARGO_BINARY_DIR}/debug")
else ()
    list(APPEND C_WITH_RUST_CARGO_FLAGS --release)
    set(C_WITH_RUST_CARGO_BINARY_DIR "${C_WITH_RUST_CARGO_BINARY_DIR}/release")
endif ()

get_filename_component(C_WITH_RUST_ROOT ${CMAKE_CURRENT_LIST_FILE} DIRECTORY)
set(C_WITH_RUST_CARGO_SOURCE_PATH ${C_WITH_RUST_ROOT}/rust)

# rust static library name
if(MSVC)
  set(JSON_PARSER_RUST_LIB "${C_WITH_RUST_CARGO_BINARY_DIR}/json_parser.lib")
else()
  set(JSON_PARSER_RUST_LIB "${C_WITH_RUST_CARGO_BINARY_DIR}/libjson_parser.a")
endif()

# NOTE: need to use cmake -E env to be portable in win
add_custom_command(
  OUTPUT ${JSON_PARSER_RUST_LIB}
  COMMAND
  ${CMAKE_COMMAND} -E env
  CARGO_TARGET_DIR=${C_WITH_RUST_CARGO_TARGET_DIR}
  ${CARGO_EXTRA_ENVS}
  RUSTFLAGS=${C_WITH_RUST_RUST_FLAGS}
  cargo build ${C_WITH_RUST_CARGO_FLAGS}
  WORKING_DIRECTORY ${C_WITH_RUST_CARGO_SOURCE_PATH}
  POST_BUILD COMMAND
  ${CMAKE_COMMAND} -E copy
  ${JSON_PARSER_RUST_LIB} "${CMAKE_CURRENT_BINARY_DIR}"
)

# rust static library and header to c language
set(C_WITH_RUST_INCLUDE ${C_WITH_RUST_ROOT}/include)
add_library(json_parser INTERFACE ${JSON_PARSER_RUST_LIB})
target_link_libraries(json_parser INTERFACE ${JSON_PARSER_RUST_LIB} ${PLATFORM_C_LINK_LIBS})

set(
  C_WITH_RUST_CPP_SRCS
  ${CMAKE_CURRENT_SOURCE_DIR}/src/main.c
)
add_executable(c-with-rust ${C_WITH_RUST_CPP_SRCS})
target_include_directories(c-with-rust PUBLIC ${C_WITH_RUST_INCLUDE})
target_link_libraries(c-with-rust PRIVATE json_parser)
file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/data.json" DESTINATION ${CMAKE_CURRENT_BINARY_DIR})