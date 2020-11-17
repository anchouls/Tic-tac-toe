#ifndef HW_02_BOARDTEST_H
#define HW_02_BOARDTEST_H

#include "Test.h"

#define DO_CHECK(EXPR)  Test::check(EXPR, __func__, __FILE__, __LINE__);


class BoardTest : public Test {
private:
    static void testCanMove1();

    static void testCanMove2();

    static void testCanMove3();

    static void testMove1();

    static void testMove2();

    static void testMove3();

    static void testCheck1();

    static void testCheck2();

    static void testCheck3();

    static void testGetState1();

    static void testGetState2();

    static void testGetState3();

    static void testGetTurn1();

    static void testGetTurn2();

    static void testGetTurn3();

    static void testGetCell1();

    static void testGetCell2();

    static void testGetCell3();

public:
    void runAllTests() override;
};

#endif //HW_02_BOARDTEST_H
