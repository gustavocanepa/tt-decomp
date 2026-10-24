#include "types.h"

extern "C" s32 func_00301F08(char *arg0);

extern "C" void func_00301F20(char *arg0) {
    if (func_00301F08(arg0) != 0) {
        char *p = arg0 + 0x7E4;
        p[2] = 0x3C;
        p[1] = 0;
        p[3] = 0;
        p[4] = 0;
        p[5] = 0;
        p[6] = 0;
    }
}
