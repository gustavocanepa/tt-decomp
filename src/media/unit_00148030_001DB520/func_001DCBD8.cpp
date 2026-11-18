#include "types.h"

extern "C" void func_001DCB80(s32 arg0, u32 arg1);

extern "C" void func_001DCBD8(void) {
    func_001DCB80(1, 0xFFFF);
}
