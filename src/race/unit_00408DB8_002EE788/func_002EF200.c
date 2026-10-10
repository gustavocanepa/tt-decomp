#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00303EA0(void *, s32, s32);            /* extern */
s32 func_003046A0(void *, s32);                 /* extern */
s32 func_0042FDB8(s32);                             /* extern */

struct func_002EF200_arg0 {
    char pad0[0x646];
    u8 unk646;
};

void func_002EF200(void *arg0) {
    s32 temp_v0;

    temp_v0 = func_0042FDB8(arg0 + 0x14);
    func_003046A0(arg0, temp_v0);
    func_00303EA0(arg0, temp_v0, ((struct func_002EF200_arg0 *)arg0)->unk646 != 2);
}
