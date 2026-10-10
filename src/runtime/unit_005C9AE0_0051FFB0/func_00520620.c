#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00520620(s32 arg0, s32 arg1) {
    s32 temp_v0;

    temp_v0 = arg1 - 1;
    return (arg0 + temp_v0) & ~temp_v0;
}
