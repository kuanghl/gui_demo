cmake_minimum_required(VERSION 2.8...3.5)

set(CMAKE_C_FLAGS "-Wall -Wextra -Werror -pedantic -O3 -D_XOPEN_SOURCE_EXTENDED -DHAVE_NCURSESW")  # -lpanelw -lncursesw

find_package(Curses REQUIRED)
# target_include_directories(pdcvt PRIVATE ${CURSES_INCLUDE_DIR}) # ${CURSES_LIBRARIES} 

# demos
add_executable(n_calendar ${PROJECT_SOURCE_DIR}/demos/calendar.c)
target_link_libraries(n_calendar ${CURSES_LIBRARIES} panelw ncursesw)

add_executable(n_init_col ${PROJECT_SOURCE_DIR}/demos/init_col.c)
target_link_libraries(n_init_col ${CURSES_LIBRARIES} panelw ncursesw)

add_executable(n_firework ${PROJECT_SOURCE_DIR}/demos/firework.c)
target_link_libraries(n_firework ${CURSES_LIBRARIES} panelw ncursesw)

add_executable(n_mbrot ${PROJECT_SOURCE_DIR}/demos/mbrot.c)
target_link_libraries(n_mbrot ${CURSES_LIBRARIES} panelw ncursesw)

add_executable(n_ozdemo ${PROJECT_SOURCE_DIR}/demos/ozdemo.c)
target_link_libraries(n_ozdemo ${CURSES_LIBRARIES} panelw ncursesw)

add_executable(n_newtest ${PROJECT_SOURCE_DIR}/demos/newtest.c)
target_link_libraries(n_newtest ${CURSES_LIBRARIES} panelw ncursesw)

add_executable(n_picsview ${PROJECT_SOURCE_DIR}/demos/picsview.c)
target_link_libraries(n_picsview ${CURSES_LIBRARIES} panelw ncursesw)

add_executable(n_ptest ${PROJECT_SOURCE_DIR}/demos/ptest.c)
target_link_libraries(n_ptest ${CURSES_LIBRARIES} panelw ncursesw)

add_executable(n_speed ${PROJECT_SOURCE_DIR}/demos/speed.c)
target_link_libraries(n_speed ${CURSES_LIBRARIES} panelw ncursesw)

add_executable(n_rain ${PROJECT_SOURCE_DIR}/demos/rain.c)
target_link_libraries(n_rain ${CURSES_LIBRARIES} panelw ncursesw)

add_executable(n_test_pan ${PROJECT_SOURCE_DIR}/demos/test_pan.c)
target_link_libraries(n_test_pan ${CURSES_LIBRARIES} panelw ncursesw)

add_executable(n_widetest ${PROJECT_SOURCE_DIR}/demos/widetest.c)
target_link_libraries(n_widetest ${CURSES_LIBRARIES} panelw ncursesw)

add_executable(n_testcurs ${PROJECT_SOURCE_DIR}/demos/testcurs.c)
target_link_libraries(n_testcurs ${CURSES_LIBRARIES} panelw ncursesw)

add_executable(n_tuidemo ${PROJECT_SOURCE_DIR}/demos/tuidemo.c ${PROJECT_SOURCE_DIR}/demos/tui.c)
target_link_libraries(n_tuidemo ${CURSES_LIBRARIES} panelw ncursesw)

add_executable(n_worm ${PROJECT_SOURCE_DIR}/demos/worm.c)
target_link_libraries(n_worm ${CURSES_LIBRARIES} panelw ncursesw)

add_executable(n_xmas ${PROJECT_SOURCE_DIR}/demos/xmas.c)
target_link_libraries(n_xmas panelw ncursesw)

# tests
add_executable(n_brk_test ${PROJECT_SOURCE_DIR}/tests/brk_test.c)
target_link_libraries(n_brk_test panel ncurses)

add_executable(n_del_test ${PROJECT_SOURCE_DIR}/tests/del_test.c)
target_link_libraries(n_del_test panel ncurses)

add_executable(n_focus ${PROJECT_SOURCE_DIR}/tests/focus.c)
target_link_libraries(n_focus panel ncurses)

add_executable(n_ins_del ${PROJECT_SOURCE_DIR}/tests/ins_del.c)
target_link_libraries(n_ins_del panel ncurses)

add_executable(n_keytest ${PROJECT_SOURCE_DIR}/tests/keytest.c)
target_link_libraries(n_keytest panel ncurses)

add_executable(n_opaque ${PROJECT_SOURCE_DIR}/tests/opaque.c)
target_link_libraries(n_opaque panel ncurses)

add_executable(n_restart ${PROJECT_SOURCE_DIR}/tests/restart.c)
target_link_libraries(n_restart panel ncurses)

add_executable(n_ripoff ${PROJECT_SOURCE_DIR}/tests/ripoff.c)
target_link_libraries(n_ripoff panel ncurses)