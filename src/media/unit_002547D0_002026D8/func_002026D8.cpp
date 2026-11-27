#include "types.h"

extern "C" void func_002BDA70(s32 arg0, s32 arg1, s32 arg2);

extern "C" void func_002026D8(s32 arg0) {
    if (arg0 != 0) {
        func_002BDA70(arg0, 0x34, 4);
    }
}
