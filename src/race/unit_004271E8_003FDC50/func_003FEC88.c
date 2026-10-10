#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_003FEB98(s32);                             /* extern */

u32 func_003FEC88(s32 *arg0) {
    return (u32) ~func_003FEB98(*arg0) >> 0x1F;
}
