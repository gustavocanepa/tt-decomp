#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004F7A30(s32, s32);                /* extern */
s32 func_004F7B74(s32, s32);                    /* extern */

extern char D_005E6AB8[];
extern char D_005E6BC8[];
s8 *func_0019E5E0(s32 arg0, s8 *arg1) {
    s32 temp_s0;

    temp_s0 = arg1 + 1;
    *arg1 = 0x2F;
    func_004F7B74(temp_s0, arg0 + 0x24);
    func_004F7A30(temp_s0, (s32)D_005E6AB8);
    func_004F7A30(temp_s0, (s32)D_005E6BC8);
    return arg1;
}
