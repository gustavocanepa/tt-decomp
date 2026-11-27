#include "types.h"

struct B {
    char pad[0x20B24];
    s8 cell[2][6];
};

extern "C" s8 func_0030E320(struct B *arg0, int row, int col) {
    return arg0->cell[row][col];
}
