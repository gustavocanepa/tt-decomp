#include "types.h"

extern "C" void func_003F8170(void *arg0) {
    *(s32 *)arg0 = (*(s32 *)arg0 & ~0xF) | 0xFFF0;
    *((s8 *)arg0 + 2) = 0;
}
