#include "types.h"

extern "C" void func_001C2A78(s32 *arg0);
extern "C" void func_001B7F98(s32 *arg0, s32 arg1);
extern "C" void func_001C4808(s32 arg0, s32 *arg1);
extern "C" void func_001B7F40(s32 *arg0, s32 arg1);
extern "C" void func_001C2A20(s32 *arg0, s32 arg1);

extern "C" void func_001C3188(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    if (arg2 == 1) {
        s32 buf0[4];
        s32 buf1[4];

        func_001C2A78(buf0);
        func_001B7F98(buf1, arg3);
        func_001C4808(buf0[0], buf1);
        func_001B7F40(buf1, 2);
        func_001C2A20(buf0, 2);
    }
}
