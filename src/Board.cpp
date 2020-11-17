#include "Board.h"

bool Board::canMove(int x, int y, cell player) {
    return board[x][y] == E && player == turn && x < N && y < N && x >= 0 && y >= 0;
}

void Board::move(int x, int y, cell player) {
    number_of_moves++;
    if (player == O) board[x][y] = O;
    else if (player == X) board[x][y] = X;
    turn = turn == O ? X : O;
    if (check(x, y, board[x][y])) state = player == X ? X_WIN : O_WIN;
    else if (number_of_moves == N*N) state = DRAW;
    else state = CONTINUE;

}

bool Board::check(int x, int y, cell v) {
    int hor = 0, ver = 0, d1 = 0, d2 = 0;
    for (int i = -K + 1; i < K; i++) {
        ver += (x + i >= 0 && x + i < N && board[x + i][y] == v) ? 1 : -ver;
        hor += (y + i >= 0 && y + i < N && board[x][y + i] == v) ? 1 : -hor;
        d1 += (x + i >= 0 && x + i < N && y + i >= 0 && y + i < N && board[x + i][y + i] == v) ? 1 : -d1;
        d2 += (x - i >= 0 && x - i < N && y + i >= 0 && y + i < N && board[x - i][y + i] == v) ? 1 : -d2;
        if (ver == K || hor == K || d1 == K || d2 == K) {
            return true;
        }
    }
    return false;
}

state Board::getState() {
    return state;
}

cell Board::getTurn() {
    return turn;
}

Board::Board() {
    turn = O;
    state = CONTINUE;
    number_of_moves = 0;
    for (auto &i : board) {
        for (cell &j : i) {
            j = E;
        }
    }
}

cell Board::getCell(int x, int y) {
    return board[x][y];
}

