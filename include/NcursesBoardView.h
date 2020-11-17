#ifndef HW_02_NCURSESBOARDVIEW_H
#define HW_02_NCURSESBOARDVIEW_H
#include <ncurses.h>
#include "BoardView.h"

class NcursesBoardView : public BoardView {
public:
    explicit NcursesBoardView(Board &board);

    std::pair<int, int> getXY() override;

    void printResult(std::string s) override;

    void printBoard() override;

    void printTurn() override ;

private:
    int x, y, row = 0, col = 0;
};


#endif //HW_02_NCURSESBOARDVIEW_H

