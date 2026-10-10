#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_002C0F28(s32);
s32 func_00297678(s8 *arg0) {
    s32 *h = (s32 *)(arg0 + 0x2C);
    s32 bad = 0;
    if (*h == 0 || func_002C0F28(*h) == 0) {
        bad = 1;
    }
    if (bad == 0) return *h;
    return 0;
}
