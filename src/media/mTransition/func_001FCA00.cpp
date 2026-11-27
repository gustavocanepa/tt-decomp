#include "types.h"

extern "C" void func_001FC948(s32 arg0, u32 arg1);

extern "C" void func_001FCA00(void) {
    func_001FC948(1, 0xFFFF);
}
