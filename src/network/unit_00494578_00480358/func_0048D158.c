#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0048D158(s32 arg0) {
    if ((u32) (arg0 - 1) < 0x1BU) {
        return *(s32 *)(0x597C88 + (arg0 * 4));
    }
    return 0;
}
