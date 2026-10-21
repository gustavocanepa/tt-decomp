#include "types.h"

struct S003A9738;

extern "C" void Oscillator__setCount(struct S003A9738 *arg0, s32 arg1, s32 arg2);

extern "C" void func_00556EC0(char *arg0, s32 arg1, s32 arg2) {
    Oscillator__setCount((struct S003A9738 *)(arg0 + 0x34), arg1, arg2);
}
