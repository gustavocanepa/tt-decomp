#include "types.h"

extern "C" void func_00370FB8();

extern "C" s32 func_00370F88(s32 arg0) {
    if (arg0 != 0) {
        func_00370FB8();
    }
    return arg0;
}
