#include "types.h"

extern "C" void func_001DB098(s32 arg0, u32 arg1);

extern "C" void func_001DB220(void) {
    func_001DB098(1, 0xFFFF);
}
