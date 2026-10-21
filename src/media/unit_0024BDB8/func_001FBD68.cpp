#include "types.h"

extern "C" void func_001FBD10(s32 arg0, u32 arg1);

extern "C" void func_001FBD68(void) {
    func_001FBD10(1, 0xFFFF);
}
