#include "types.h"

extern "C" void func_0035E6B0(char *arg0, u8 arg1) {
    s32 *p = (s32 *)(arg0 + 0xA44);
    *p = (*p & ~0xFF) | arg1;
}
