cmake_minimum_required(VERSION 3.10)
project(hw_02)

set(CMAKE_CXX_STANDARD 14)

include_directories(include/)

add_executable(hw_02 src/main.cpp src/Board.cpp include/Board.h src/StdioBoardView.cpp include/StdioBoardView.h include/NcursesBoardView.h src/NcursesBoardView.cpp include/BoardView.h include/GameController.h src/BoardView.cpp src/GameController.cpp)
add_executable(test_hw_02 test/test_main.cpp test/BoardTest.cpp include/BoardTest.h test/Test.cpp include/Test.h src/Board.cpp include/Board.h)
target_link_libraries(${PROJECT_NAME} ncurses)