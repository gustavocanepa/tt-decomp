#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004B0AB8(void *, s32);             /* extern */
s32 func_004AE9F0(s32, s32);                /* extern */
s32 func_0050E1A8(void *);                      /* extern */

extern char D_005DA5F8[];
struct func_0047D860_arg0 {
    char pad0[0x30];
    s32 unk30;
};

void func_0047D860(void *arg0, s32 arg1) {
    ((struct func_0047D860_arg0 *)arg0)->unk30 = (s32)D_005DA5F8;
    func_004AE9F0(arg0 + 0x1838, 2);
    func_004B0AB8(arg0, 0);
    if (arg1 & 1) {
        func_0050E1A8(arg0);
    }
}
