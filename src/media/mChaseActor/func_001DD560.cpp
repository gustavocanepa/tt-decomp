#include "types.h"

extern "C" void func_001DD508(s32 arg0, u32 arg1);

extern "C" void func_001DD560(void) {
    func_001DD508(1, 0xFFFF);
}
