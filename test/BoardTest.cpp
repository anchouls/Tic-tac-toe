#include "BoardTest.h"
#include "Board.h"


void BoardTest::testCanMove1() {
    Board b;
    DO_CHECK(!b.canMove(11, 11, X))
}

void BoardTest::testCanMove2() {
    Board b;
    b.move(0, 0, O);
    DO_CHECK(!b.canMove(1, 1, O))
}

void BoardTest::testCanMove3() {
    Board b;
    b.move(0, 0, X);
    DO_CHECK(!b.canMove(0, 0, O))
}

void BoardTest::testMove1() {
    Board b;
    b.move(0, 0, O);
    b.move(1, 1, X);
    DO_CHECK(b.getCell(0, 0) == O)
}

void BoardTest::testMove2() {
    Board b;
    b.move(0, 0, O);
    b.move(1, 1, X);
    DO_CHECK(b.getCell(1, 1) == X)
}

void BoardTest::testMove3() {
    Board b;
    b.move(0, 0, O);
    b.move(1, 0, X);
    b.move(0, 1, O);
    b.move(1, 1, X);
    b.move(0, 2, O);
    b.move(1, 2, X);
    b.move(0, 3, O);
    b.move(1, 3, X);
    b.move(5, 4, O);
    b.move(1, 4, X);
    DO_CHECK(b.getCell(9, 9) == E)
}

void BoardTest::testCheck1() {
    Board b;
    b.move(0, 0, O);
    b.move(1, 0, X);
    b.move(0, 1, O);
    b.move(1, 1, X);
    b.move(0, 2, O);
    b.move(1, 2, X);
    b.move(0, 3, O);
    b.move(1, 3, X);
    b.move(5, 4, O);
    b.move(1, 4, X);
    DO_CHECK(b.check(1, 0, X))
}

void BoardTest::testCheck2() {
    Board b;
    b.move(0, 0, O);
    b.move(1, 0, X);
    b.move(1, 0, O);
    b.move(1, 1, X);
    b.move(2, 0, O);
    b.move(1, 2, X);
    b.move(3, 0, O);
    b.move(1, 3, X);
    b.move(4, 0, O);
    DO_CHECK(b.check(0, 0, O))
}

void BoardTest::testCheck3() {
    Board b;
    b.move(0, 0, O);
    b.move(5, 0, X);
    b.move(1, 1, O);
    b.move(5, 1, X);
    b.move(2, 2, O);
    b.move(5, 2, X);
    b.move(3, 3, O);
    b.move(5, 3, X);
    b.move(4, 4, O);
    DO_CHECK(b.check(0, 0, O))
}

void BoardTest::testGetState1() {
    Board b;
    b.move(0, 0, O);
    b.move(1, 1, X);
    DO_CHECK(b.getState() == CONTINUE)
}

void BoardTest::testGetState2() {
    Board b;
    b.move(0, 0, O);
    b.move(1, 0, X);
    b.move(0, 1, O);
    b.move(1, 1, X);
    b.move(0, 2, O);
    b.move(1, 2, X);
    b.move(0, 3, O);
    b.move(1, 3, X);
    b.move(0, 4, O);
    DO_CHECK(b.getState() == O_WIN)
}

void BoardTest::testGetState3() {
    Board b;
    b.move(0, 0, O);
    b.move(1, 0, X);
    b.move(0, 1, O);
    b.move(1, 1, X);
    b.move(0, 2, O);
    b.move(1, 2, X);
    b.move(0, 3, O);
    b.move(1, 3, X);
    b.move(5, 4, O);
    b.move(1, 4, X);
    DO_CHECK(b.getState() == X_WIN)
}

void BoardTest::testGetTurn1() {
    Board b;
    b.move(1, 1, O);
    b.move(0, 0, X);
    DO_CHECK(b.getTurn() == O)
}

void BoardTest::testGetTurn2() {
    Board b;
    b.move(0, 0, O);
    DO_CHECK(b.getTurn() == X)
}

void BoardTest::testGetTurn3() {
    Board b;
    b.move(0, 0, O);
    b.move(1, 0, X);
    b.move(0, 1, O);
    b.move(1, 1, X);
    b.move(0, 2, O);
    b.move(1, 2, X);
    b.move(0, 3, O);
    b.move(1, 3, X);
    b.move(5, 4, O);
    b.move(1, 4, X);
    DO_CHECK(b.getTurn() == O)
}

void BoardTest::testGetCell1() {
    Board b;
    b.move(0, 0, X);
    DO_CHECK(b.getCell(0, 0) == X)
}

void BoardTest::testGetCell2() {
    Board b;
    b.move(0, 0, O);
    DO_CHECK(b.getCell(0, 0) == O)
}

void BoardTest::testGetCell3() {
    Board b;
    b.move(0, 0, X);
    DO_CHECK(b.getCell(1, 1) == E)
}

void BoardTest::runAllTests() {
    testCanMove1();
    testCanMove2();
    testCanMove3();
    testMove1();
    testMove2();
    testMove3();
    testCheck1();
    testCheck2();
    testCheck3();
    testGetState1();
    testGetState2();
    testGetState3();
    testGetTurn1();
    testGetTurn2();
    testGetTurn3();
    testGetCell1();
    testGetCell2();
    testGetCell3();
}





