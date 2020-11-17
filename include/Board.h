#ifndef HW_02_BOARD_H
#define HW_02_BOARD_H

enum cell{X = 'X', O = 'O', E = '.'};

enum state{CONTINUE, DRAW, X_WIN, O_WIN};

const int N = 10;
const int K = 5;

class Board {
public:

    Board();

    /** Проверить ход на корректность, если бы он был следующим. */
    bool canMove(int x, int y, cell player);


    /** Сделать ход. UB, если он некорректен. */
    void move(int x, int y, cell player);

    bool check(int x, int y, cell v);

    /** Состояние игры: игра идёт, игра кончилась с одним из результатов: ничья, победа одной из сторон. */
    state getState();

    cell getTurn();

    cell getCell(int x, int y);

    ~Board() = default;

protected:
    cell board[N][N];
    cell turn ;
    state state;
    int number_of_moves;
};

#endif //HW_02_BOARD_H