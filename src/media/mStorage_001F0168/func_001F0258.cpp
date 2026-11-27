#include "types.h"

extern "C" void func_001F0200(s32 arg0, u32 arg1);

extern "C" void func_001F0258(void) {
    func_001F0200(1, 0xFFFF);
}
