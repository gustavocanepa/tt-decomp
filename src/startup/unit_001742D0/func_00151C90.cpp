#include "types.h"

extern "C" void func_001DD3C8(s32 arg0);

extern "C" void func_00151C90(s32 *arg0) {
    if (arg0 != 0) {
        func_001DD3C8(*arg0);
    }
}
