cmake_minimum_required(VERSION 2.8...3.5)

set(CMAKE_C_FLAGS "-Wall -Wextra -pedantic -Werror -O2 -fPIC -DHAVE_VSNPRINTF -DHAVE_VSSCANF -DPDC_WIDE")

# pdcurses .c add
file(GLOB pdcurses_src "${PROJECT_SOURCE_DIR}/pdcurses/*.c")

# deps .c add
set(pdc_fb_src_files 
    ${CMAKE_CURRENT_SOURCE_DIR}/pdcclip.c
    ${CMAKE_CURRENT_SOURCE_DIR}/pdcdisp.c
    ${CMAKE_CURRENT_SOURCE_DIR}/pdcgetsc.c
    ${CMAKE_CURRENT_SOURCE_DIR}/pdckbd.c
    ${CMAKE_CURRENT_SOURCE_DIR}/pdcscrn.c
    ${CMAKE_CURRENT_SOURCE_DIR}/pdcsetsc.c
    ${CMAKE_CURRENT_SOURCE_DIR}/pdcutil.c
    ${CMAKE_CURRENT_SOURCE_DIR}/psf.c)

# vt library
add_library(pdcfb STATIC ${pdc_fb_src_files} ${pdcurses_src})
target_link_libraries(pdcfb)
target_include_directories(pdcfb    PUBLIC ${PROJECT_SOURCE_DIR}
                                    PRIVATE ${PROJECT_SOURCE_DIR}/common ${CMAKE_CURRENT_SOURCE_DIR})

# test demos
add_executable(fb_calendar ${PROJECT_SOURCE_DIR}/demos/calendar.c)
target_link_libraries(fb_calendar pdcfb)

add_executable(fb_firework ${PROJECT_SOURCE_DIR}/demos/firework.c)
target_link_libraries(fb_firework pdcfb)

add_executable(fb_init_col ${PROJECT_SOURCE_DIR}/demos/init_col.c)
target_link_libraries(fb_init_col pdcfb)

add_executable(fb_mbrot ${PROJECT_SOURCE_DIR}/demos/mbrot.c)
target_link_libraries(fb_mbrot pdcfb)

add_executable(fb_newtest ${PROJECT_SOURCE_DIR}/demos/newtest.c)
target_link_libraries(fb_newtest pdcfb)

add_executable(fb_ozdemo ${PROJECT_SOURCE_DIR}/demos/ozdemo.c)
target_link_libraries(fb_ozdemo pdcfb)

add_executable(fb_picsview ${PROJECT_SOURCE_DIR}/demos/picsview.c)
target_link_libraries(fb_picsview pdcfb)

add_executable(fb_ptest ${PROJECT_SOURCE_DIR}/demos/ptest.c)
target_link_libraries(fb_ptest pdcfb)

add_executable(fb_rain ${PROJECT_SOURCE_DIR}/demos/rain.c)
target_link_libraries(fb_rain pdcfb)

add_executable(fb_speed ${PROJECT_SOURCE_DIR}/demos/speed.c)
target_link_libraries(fb_speed pdcfb)

add_executable(fb_test_pan ${PROJECT_SOURCE_DIR}/demos/test_pan.c)
target_link_libraries(fb_test_pan pdcfb)

add_executable(fb_testcurs ${PROJECT_SOURCE_DIR}/demos/testcurs.c)
target_link_libraries(fb_testcurs pdcfb)

add_executable(fb_widetest ${PROJECT_SOURCE_DIR}/demos/widetest.c)
target_link_libraries(fb_widetest pdcfb)

add_executable(fb_worm ${PROJECT_SOURCE_DIR}/demos/worm.c)
target_link_libraries(fb_worm pdcfb)

add_executable(fb_xmas ${PROJECT_SOURCE_DIR}/demos/xmas.c)
target_link_libraries(fb_xmas pdcfb)

add_executable(fb_version ${PROJECT_SOURCE_DIR}/demos/version.c)
target_link_libraries(fb_version pdcfb)