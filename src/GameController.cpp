#include <GameController.h>

GameController::GameController(Board &board, BoardView *view) : board(board), view(view) {}

void GameController::runGame() {
    while(board.getState() == CONTINUE){
        view->printBoard();
        view->printTurn();
        std::pair<int, int> xy = view->getXY();
        int x = xy.first,y = xy.second;
        board.move(x,y,board.getTurn());
    }
    view->printBoard();
    if (board.getState() == DRAW) view->printResult("Draw.");
    else if (board.getState() == O_WIN) view->printResult("O wins!");
    if (board.getState() == X_WIN) view->printResult("X wins!");
}

