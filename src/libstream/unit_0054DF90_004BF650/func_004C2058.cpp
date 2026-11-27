#include "types.h"

extern "C" void func_004C2000(s32 arg0, u32 arg1);

extern "C" void func_004C2058(void) {
    func_004C2000(1, 0xFFFF);
}
