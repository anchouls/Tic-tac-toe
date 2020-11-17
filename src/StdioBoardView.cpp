#include "StdioBoardView.h"
#include <iostream>
#include <sstream>

StdioBoardView::StdioBoardView(Board &board, bool silent) : BoardView(board) {
    this->silent = silent;
}

void StdioBoardView::printBoard() {
    if (!silent || board.getState() != CONTINUE) {
        std::cout << std::endl;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                std::cout << (char) board.getCell(i, j) << ' ';
            }
            std::cout << std::endl;
        }
    }
}


std::pair<int, int> StdioBoardView::getXY() {
    int x, y;
    std::string s;
    getline(std::cin, s);
    std::stringstream ss;
    ss << s;
    int temp;
    x = 0, y = 0;
    int counter = 0;
    while (ss >> temp) {
        counter++;
        if (counter > 2)
            return badMove();
        if (temp > -2 && temp < N)
            if (counter == 1) {
                x = temp;
            } else {
                y = temp;
                char c;
                while (ss >> c) {
                    if (c != ' ')
                        return badMove();
                }
            }
        else
            return badMove();
    }
    if (counter < 2)
        return badMove();
    if (x == -1 && y == -1) {
        exit(0);
    }
    if (board.canMove(x, y, board.getTurn())) return {x, y};
    else return badMove();
}


void StdioBoardView::printResult(std::string s) {
    std::cout << s << std::endl;
}

void StdioBoardView::printTurn() {
    if (board.getTurn() == O) std::cout << "O move: ";
    if (board.getTurn() == X) std::cout << "X move: ";
}

std::pair<int,int> StdioBoardView::badMove() {
    std::cout << "Bad move!" << std::endl;
    printTurn();
    return getXY();
}

