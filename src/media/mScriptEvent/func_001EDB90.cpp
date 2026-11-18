#include "types.h"

extern "C" void func_001EDB38(s32 arg0, u32 arg1);

extern "C" void func_001EDB90(void) {
    func_001EDB38(1, 0xFFFF);
}
