#include "types.h"

extern "C" void func_001DEBD0(s32 arg0, u32 arg1);

extern "C" void func_001DED00(void) {
    func_001DEBD0(1, 0xFFFF);
}
