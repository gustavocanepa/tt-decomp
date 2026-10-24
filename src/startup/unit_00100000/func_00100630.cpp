#include "types.h"

extern "C" void func_001005B8(s32 arg0, u32 arg1);

extern "C" void func_00100630(void) {
    func_001005B8(0, 0xFFFF);
}
