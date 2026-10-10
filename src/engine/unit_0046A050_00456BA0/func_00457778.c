#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0045A3A8(s32, s32);                /* extern */
s32 func_0045A430(s32, s32);                /* extern */
s32 func_0045A4B8(s32, s32);                /* extern */
s32 func_0045A560(s32, s32, s32);       /* extern */
s32 func_0045A688(s32);                             /* extern */

extern char D_00602510[];
s32 func_00457778(s32 arg0, s32 *arg1, s32 *arg2) {
    s32 temp_s0;

    temp_s0 = arg0 + 0x85C;
    func_0045A3A8(temp_s0, 0xFFE1);
    *arg1 = func_0045A688(temp_s0);
    func_0045A3A8(temp_s0, 0);
    func_0045A560(temp_s0, (s32)D_00602510, 6);
    *arg2 = func_0045A688(temp_s0);
    func_0045A3A8(temp_s0, 0x4949);
    func_0045A430(temp_s0, 0x2A);
    func_0045A4B8(temp_s0, 8);
    return 0x10;
}
