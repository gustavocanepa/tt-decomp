#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_001AFE98();                            /* extern */
s32 func_004AE9F0(void *, s32);             /* extern */
s32 func_0050E1A8(void *);                      /* extern */

extern char D_005ADAB8[];
struct func_001AF878_arg0 {
    char pad0[0x5C];
    s32 unk5C;
};

void func_001AF878(void *arg0, s32 arg1) {
    ((struct func_001AF878_arg0 *)arg0)->unk5C = (s32)D_005ADAB8;
    func_001AFE98();
    func_004AE9F0((char *)arg0 + 0x2C, 2);
    if (arg1 & 1) {
        func_0050E1A8(arg0);
    }
}
