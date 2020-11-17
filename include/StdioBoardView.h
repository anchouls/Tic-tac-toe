#ifndef HW_02_STDIOBOARDVIEW_H
#define HW_02_STDIOBOARDVIEW_H

#include "BoardView.h"

class StdioBoardView : public BoardView {
public:
    StdioBoardView(Board &board, bool silent);

    std::pair<int, int> getXY() override;

    void printResult(std::string s) override;

    void printBoard() override;

    void printTurn() override ;

private:
    bool silent;

    std::pair<int,int> badMove();

};

#endif //HW_02_STDIOBOARDVIEW_Hs
