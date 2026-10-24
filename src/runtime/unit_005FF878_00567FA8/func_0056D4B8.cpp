#include "types.h"

extern "C" void func_0056D4B8(void *arg0, s32 arg1) {
    u32 base = (u32)arg0 + 0xC;
    u32 addr0 = (arg1 << 8) + base;
    s32 v = *(s32 *)(addr0 + 0x750);
    u32 addr1 = (arg1 << 2) + base;
    *(s32 *)(addr1 + 0xA50) = v;
}
