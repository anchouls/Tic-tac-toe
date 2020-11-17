#ifndef HW_02_GAMECONTROLLER_H
#define HW_02_GAMECONTROLLER_H

#include "BoardView.h"

class GameController {
public:
    void runGame();

    GameController(Board &board, BoardView *view);

private:
    Board &board;
    BoardView *view;
};

#endif //HW_02_GAMECONTROLLER_H
