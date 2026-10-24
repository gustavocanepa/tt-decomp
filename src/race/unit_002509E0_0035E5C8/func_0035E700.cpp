#include "types.h"

extern "C" void func_0035E700(char *arg0, u8 arg1) {
    s32 *p = (s32 *)(arg0 + 0xBF0);
    *p = (*p & ~0xFF) | arg1;
}
