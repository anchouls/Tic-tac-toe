#include "StdioBoardView.h"
#include "NcursesBoardView.h"
#include <cstring>
#include <GameController.h>

int main(int argc, char **argv) {
    auto board = new Board();
    BoardView *view;
    bool silent = false;
    bool ncurses = false;
    if (argc > 1) {
        if (!strcmp(argv[1], "silent")) {
            silent = true;
        } else if (!strcmp(argv[1], "ncurses")) {
            ncurses = true;
        }
    }
    if (ncurses) {
        view = new NcursesBoardView(*board);
    } else {
        view = new StdioBoardView(*board, silent);
    }
    GameController game(*board, view);
    game.runGame();
    return 0;
}