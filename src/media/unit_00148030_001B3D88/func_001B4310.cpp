#include "types.h"

extern "C" void func_001B42B8(s32 arg0, u32 arg1);

extern "C" void func_001B4310(void) {
    func_001B42B8(1, 0xFFFF);
}
