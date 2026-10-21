#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0045A0E8(s32, s32);                /* extern */
s32 func_0045BEF8(s32, s32);                /* extern */
s32 func_0050E1A8(void *);                      /* extern */

extern char D_005DA1A8[];
struct func_00456BE8_arg0 {
    char pad0[0x8E8];
    s32 unk8E8;
};

void func_00456BE8(void *arg0, s32 arg1) {
    s32 temp_s2;

    temp_s2 = arg0 + 0xC;
    ((struct func_00456BE8_arg0 *)arg0)->unk8E8 = (s32)D_005DA1A8;
    func_0045A0E8(arg0 + 0x85C, 2);
    func_0045BEF8(temp_s2, 2);
    if (arg1 & 1) {
        func_0050E1A8(arg0);
    }
}
