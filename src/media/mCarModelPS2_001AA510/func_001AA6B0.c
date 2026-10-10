#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_001AA6B0(s32 *arg0, f32 fparg0) {
    if (fparg0 < 0x1.0000000000000p-1f) {
        *arg0 = (s32) *arg0 / 2;
    }
    if (fparg0 < 0x1.0000000000000p-2f) {
        *arg0 = (s32) *arg0 / 2;
    }
    if (*arg0 <= 0) {
        *arg0 = 1;
    }
    return 0;
}
