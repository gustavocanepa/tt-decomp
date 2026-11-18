#include "types.h"

extern "C" void func_004B03A0(s8 **arg0, s32 arg1, s32 arg2) {
    s8 *p;

    p = *arg0 + arg1;
    arg2 += *p;
    *p = (s8)arg2;
}
