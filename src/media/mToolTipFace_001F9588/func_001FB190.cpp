#include "types.h"

extern "C" void func_001FB048(s32 arg0, u32 arg1);

extern "C" void func_001FB190(void) {
    func_001FB048(0, 0xFFFF);
}
