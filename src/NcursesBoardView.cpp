#include "NcursesBoardView.h"
#include <cstdlib>


NcursesBoardView::NcursesBoardView(Board &board) : BoardView(board) {
    initscr();
    this->x = 0;
    this->y = 0;
    getmaxyx(stdscr, row, col);
    curs_set(0);
    keypad(stdscr, true);
}

void NcursesBoardView::printBoard() {
    clear();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            move(i, j);
            if (x == i && y == j)
                addch((char) board.getCell(i, j) | A_STANDOUT);
            else
                addch((char) board.getCell(i, j));
        }
    }
    mvwprintw(stdscr, 10, 0, "Current position is (%d, %d)\n", x, y);
    mvwprintw(stdscr, 11, 0, "%c move: \n", (char) board.getTurn());
}

void NcursesBoardView::printResult(std::string s) {
    clear();
    mvwprintw(stdscr, row / 2, (int) (col - s.length()) / 2, s.c_str());
    getch();
    endwin();
}


std::pair<int, int> NcursesBoardView::getXY() {
    while (true) {
        printBoard();
        switch (getch()) {
            case KEY_UP:
                if (x)
                    x--;
                break;
            case KEY_DOWN:
                if (x != N - 1)
                    x++;
                break;
            case KEY_LEFT:
                if (y)
                    y--;
                break;
            case KEY_RIGHT:
                if (y != N - 1)
                    y++;
                break;
            case ' ':
                return {x, y};
            case 'x':
                endwin();
                exit(0);
        }

    }

}

void NcursesBoardView::printTurn() {}


