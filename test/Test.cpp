#include "Test.h"
#include <cstdio>

void Test::check(bool expr, const char *func, const char *filename, size_t lineNum) {
    totalNum++;
    if (!expr) {
        failedNum++;
        fprintf(stdout, "test failed: %s in %s:%lud\n", func, filename, lineNum);
    }
}

void Test::showFinalResults() {
    if (!failedNum) fprintf(stdout, "OK\n");
    else fprintf(stdout, "Failed %d of %d test.\n", failedNum, totalNum);
}

int Test::failedNum = 0;
int Test::totalNum = 0;




