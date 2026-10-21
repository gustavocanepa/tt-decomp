#include "types.h"

extern "C" void func_001C2868(s32 arg0, u32 arg1);

extern "C" void func_001C2920(void) {
    func_001C2868(1, 0xFFFF);
}
