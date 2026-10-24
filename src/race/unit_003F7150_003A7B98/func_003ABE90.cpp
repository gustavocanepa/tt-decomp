#include "types.h"

extern "C" void func_003ABE90(char *arg0, s32 arg1) {
    *(s32 *)(arg0 + 0x0) = arg1;
    *(s32 *)(arg0 + 0x1C) = 1;
    *(f32 *)(arg0 + 0x18) = 8.0f;
    *(s32 *)(arg0 + 0x4) = 0;
    *(s32 *)(arg0 + 0x20) = 0;
}
