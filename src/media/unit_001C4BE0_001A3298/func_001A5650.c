#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_00101678();                            /* extern */
s32 func_001A67B0();                            /* extern */
s32 func_001A78E0(void *, s32);             /* extern */
s32 func_004A45D0(s32);                         /* extern */
s32 func_004A8A88(s32, s32, s32);       /* extern */
s32 func_0050E1A8(void *);                      /* extern */

struct func_001A5650_arg0 {
    char pad0[0x64];
    s32 unk64;
    s32 unk68;
};

void func_001A5650(void *arg0, s32 arg1) {
    func_001A67B0();
    func_004A8A88(((struct func_001A5650_arg0 *)arg0)->unk68, 0, 0);
    func_00101678();
    func_004A45D0(((struct func_001A5650_arg0 *)arg0)->unk64);
    func_001A78E0(arg0 + 0x20, 2);
    if (arg1 & 1) {
        func_0050E1A8(arg0);
    }
}
