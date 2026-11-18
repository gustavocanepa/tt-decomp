#include "types.h"

extern "C" void func_001A5A60(void *, s32, s32);
extern "C" void func_001A5928(void *, s32, s32);

extern "C" void func_001A58E8(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    if (arg1 != 0) {
        func_001A5A60(arg0, arg2, arg3);
        return;
    }
    do {
        func_001A5928(arg0, arg2, arg3);
    } while (0);
}
