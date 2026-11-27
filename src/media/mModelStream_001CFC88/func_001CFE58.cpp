#include "types.h"

extern "C" void func_001CFE00(s32 arg0, u32 arg1);

extern "C" void func_001CFE58(void) {
    func_001CFE00(1, 0xFFFF);
}
