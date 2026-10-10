#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_004A4690(s32, s32);                    /* extern */
s32 func_004FAAA0(s32);                     /* extern */

s32 func_004CBB88(s32 arg0) {
    s32 temp_s0;

    temp_s0 = func_004A4690(0x80, ((u32) (arg0 + 0x3F) >> 6) << 6);
    func_004FAAA0(0);
    return temp_s0;
}
