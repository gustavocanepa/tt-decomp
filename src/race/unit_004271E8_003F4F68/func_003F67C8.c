#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_003F67C8(u8 *arg0) {
    u8 temp_v0;

    temp_v0 = *arg0;
    if (temp_v0 < 9U) {
        return *(s32 *)(0x5855D0 + (temp_v0 * 4));
    }
    return 0;
}
