#include "types.h"

struct Elem {
    char pad[0xCB0];
    s32 unkCB0;
};

extern "C" void func_0039D050(char *arg0, s32 arg1) {
    ((Elem *)(arg0 + arg1 * 0x8D0))->unkCB0 = 1;
}
