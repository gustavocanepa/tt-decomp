#include "types.h"

extern "C" int func_00411790(int, s64);

extern "C" int func_0040B9F8(char *base, s64 arg1) {
    s32 idx = (s32)(arg1 >> 32);
    u64 lo = (u64)arg1 & 0xFFFFFFFFUL;
    s32 v = *(s32 *)(base + idx * 4 + 0x138);
    if (v == 0) {
        return -1;
    }
    return func_00411790(v, (s64)(s32)lo);
}
