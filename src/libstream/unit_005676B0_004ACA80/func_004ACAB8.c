#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004AE9F0(s32, s32);                /* extern */
s32 func_004AC770(void *, s32);             /* extern */
s32 func_0050E1A8(void *);                      /* extern */

extern char D_005DADF8[];
struct func_004ACAB8_arg0 {
    char pad0[0x8];
    s32 unk8;
};

void func_004ACAB8(void *arg0, s32 arg1) {
    ((struct func_004ACAB8_arg0 *)arg0)->unk8 = (s32)D_005DADF8;
    func_004AE9F0(arg0 + 0xC, 2);
    func_004AC770(arg0, 0);
    if (arg1 & 1) {
        func_0050E1A8(arg0);
    }
}
