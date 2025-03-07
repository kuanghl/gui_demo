cmake_minimum_required(VERSION 2.8...3.5)

set(CMAKE_C_FLAGS "-O2 -Wall -Wextra -pedantic -Werror -DHAVE_CONFIG_H -DXCURSES  -DPDC_WIDE -fPIC -DDYNAMIC")

# pdcurses .c add
file(GLOB pdcurses_src "${PROJECT_SOURCE_DIR}/pdcurses/*.c")

# Find X11 package
find_package(X11 REQUIRED)
include_directories(${X11_INCLUDE_DIR})
# message(STATUS "X11 include:${X11_INCLUDE_DIR}  library:${X11_LIBRARIES}")

# deps .c add
set(pdc_x11_src_files 
    ${CMAKE_CURRENT_SOURCE_DIR}/pdcclip.c
    ${CMAKE_CURRENT_SOURCE_DIR}/pdcdisp.c
    ${CMAKE_CURRENT_SOURCE_DIR}/pdcgetsc.c
    ${CMAKE_CURRENT_SOURCE_DIR}/pdckbd.c
    ${CMAKE_CURRENT_SOURCE_DIR}/pdcscrn.c
    ${CMAKE_CURRENT_SOURCE_DIR}/pdcsetsc.c
    ${CMAKE_CURRENT_SOURCE_DIR}/pdcutil.c
    ${CMAKE_CURRENT_SOURCE_DIR}/sb.c
    ${CMAKE_CURRENT_SOURCE_DIR}/scrlbox.c)

# vt library
add_library(pdcx11 STATIC ${pdc_x11_src_files} ${pdcurses_src}) 
target_link_libraries(pdcx11 ${X11_LIBRARIES} Xt Xaw Xmu Xext SM Xpm)
target_include_directories(pdcx11   PUBLIC ${PROJECT_SOURCE_DIR} 
                                    PRIVATE ${PROJECT_SOURCE_DIR}/common 
                                            ${CMAKE_CURRENT_SOURCE_DIR}
                                            ${X11_INCLUDE_DIR}/X11
                                            ${X11_INCLUDE_DIR}/X11/Xmu)

# test demos
add_executable(x11_firework ${PROJECT_SOURCE_DIR}/demos/firework.c)
target_link_libraries(x11_firework pdcx11)

add_executable(x11_init_col ${PROJECT_SOURCE_DIR}/demos/init_col.c)
target_link_libraries(x11_init_col pdcx11)

add_executable(x11_mbrot ${PROJECT_SOURCE_DIR}/demos/mbrot.c)
target_link_libraries(x11_mbrot pdcx11)

add_executable(x11_ozdemo ${PROJECT_SOURCE_DIR}/demos/ozdemo.c)
target_link_libraries(x11_ozdemo pdcx11)

add_executable(x11_newtest ${PROJECT_SOURCE_DIR}/demos/newtest.c)
target_link_libraries(x11_newtest pdcx11)

add_executable(x11_picsview ${PROJECT_SOURCE_DIR}/demos/picsview.c)
target_link_libraries(x11_picsview pdcx11)

add_executable(x11_ptest ${PROJECT_SOURCE_DIR}/demos/ptest.c)
target_link_libraries(x11_ptest pdcx11)

add_executable(x11_rain ${PROJECT_SOURCE_DIR}/demos/rain.c)
target_link_libraries(x11_rain pdcx11)

add_executable(x11_speed ${PROJECT_SOURCE_DIR}/demos/speed.c)
target_link_libraries(x11_speed pdcx11)

add_executable(x11_test_pan ${PROJECT_SOURCE_DIR}/demos/test_pan.c)
target_link_libraries(x11_test_pan pdcx11)

add_executable(x11_testcurs ${PROJECT_SOURCE_DIR}/demos/testcurs.c)
target_link_libraries(x11_testcurs pdcx11)

add_executable(x11_tuidemo ${PROJECT_SOURCE_DIR}/demos/tuidemo.c ${PROJECT_SOURCE_DIR}/demos/tui.c)
target_link_libraries(x11_tuidemo pdcx11)

add_executable(x11_widetest ${PROJECT_SOURCE_DIR}/demos/widetest.c)
target_link_libraries(x11_widetest pdcx11)

add_executable(x11_worm ${PROJECT_SOURCE_DIR}/demos/worm.c)
target_link_libraries(x11_worm pdcx11)

add_executable(x11_xmas ${PROJECT_SOURCE_DIR}/demos/xmas.c)
target_link_libraries(x11_xmas pdcx11)

add_executable(x11_version ${PROJECT_SOURCE_DIR}/demos/version.c)
target_link_libraries(x11_version pdcx11)