#include "types.h"

extern "C" void func_00552F08(void *arg0, u32 arg1);
extern char D_0076A090[];
extern s32 D_00585F24;

extern "C" void func_0042D2E8(s32 arg0) {
    D_00585F24 = (s32)(arg0 == 1);
    func_00552F08(D_0076A090, 0x12345678);
}
