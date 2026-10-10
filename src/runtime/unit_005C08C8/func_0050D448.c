#include "types.h"
void *memcpy(void *, const void *, unsigned int);

u32 func_004A8268(s32, s32);                        /* extern */

u32 func_0050D448(s32 *arg0, s32 *arg1) {
    return func_004A8268(*arg0, *arg1) >> 0x1F;
}
