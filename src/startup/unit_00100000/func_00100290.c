#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00100970(void *, s32);             /* extern */
s32 func_004AE9F0(s32, s32);                /* extern */
s32 func_0050E1A8(void *);                      /* extern */

extern char D_005A4860[];
struct func_00100290_arg0 {
    char pad0[0x64];
    s32 unk64;
};

void func_00100290(void *arg0, s32 arg1) {
    ((struct func_00100290_arg0 *)arg0)->unk64 = (s32)D_005A4860;
    func_004AE9F0(arg0 + 0x6C, 2);
    func_00100970(arg0, 0);
    if (arg1 & 1) {
        func_0050E1A8(arg0);
    }
}
