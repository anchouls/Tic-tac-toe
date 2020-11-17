#ifndef HW_02_BOARDVIEW_H
#define HW_02_BOARDVIEW_H

#include <utility>
#include <string>
#include "Board.h"

class BoardView{
public:
    explicit BoardView(Board &board);
    virtual void printBoard() = 0;
    virtual void printTurn() = 0;
    virtual std::pair<int,int> getXY() = 0;
    virtual void printResult(std::string s) = 0;

protected:
    Board &board;
};

#endif //HW_02_BOARDVIEW_H
