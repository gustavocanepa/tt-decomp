#include "types.h"

extern "C" void func_00100D50(s32 arg0, u32 arg1);

extern "C" void func_00100DF8(void) {
    func_00100D50(1, 0xFFFF);
}
