#include "types.h"

extern "C" void func_001A3328(char *arg0, s32 arg1, s32 arg2) {
    u8 *p1;
    s8 *p0;
    s8 t;

    p0 = (s8 *)(arg0 + arg1);
    p1 = (u8 *)(arg0 + arg2);
    t = *p0;
    *p0 = (s8)*p1;
    *p1 = (u8)t;
}
