#include "types.h"

extern "C" void func_001FC6A8(s32 arg0, u32 arg1);

extern "C" void func_001FC700(void) {
    func_001FC6A8(1, 0xFFFF);
}
