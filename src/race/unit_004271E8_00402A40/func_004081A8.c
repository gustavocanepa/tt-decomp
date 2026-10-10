#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s64 func_004082B0(s32);
struct func_004081A8_arg0 {
    char pad0[0x4D8];
    s32 unk4D8;
};

s32 func_004081A8(s8 *arg0, s32 arg1) {
    s64 r = func_004082B0(arg1);
    s8 *e = arg0 + ((struct func_004081A8_arg0 *)arg0)->unk4D8 * 0x190;
    return *(s64 *)(e + 0x108) == r;
}
