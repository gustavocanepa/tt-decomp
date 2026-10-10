#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00480F90(void *, s32);             /* extern */
s32 func_0047A0E8(s32, s32);                /* extern */
s32 func_0047BDF8(void *, s32);             /* extern */
s32 func_0050E1A8(void *);                      /* extern */

extern char D_005DA2E0[];
struct func_0047A1D0_arg0 {
    char pad0[0xA4];
    s32 unkA4;
};

void func_0047A1D0(void *arg0, s32 arg1) {
    ((struct func_0047A1D0_arg0 *)arg0)->unkA4 = (s32)D_005DA2E0;
    func_0047A0E8(arg0 + 0xE8, 2);
    func_0047BDF8(arg0 + 0xC4, 2);
    func_00480F90(arg0, 0);
    if (arg1 & 1) {
        func_0050E1A8(arg0);
    }
}
