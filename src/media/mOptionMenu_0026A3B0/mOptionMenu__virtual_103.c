#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_001BA1B0(s32);                             /* extern */
s32 func_0020D6C8(s32, s32);                /* extern */
s32 func_0026AB58(void *, s32);                 /* extern */
s32 func_002A75A8(void *, s32);             /* extern */
s32 func_002A7A30(void *);                      /* extern */
s32 func_004AC4D0(void *, s32, s32);        /* extern */

struct mOptionMenu__virtual_103_arg0 {
    char pad0[0xDC];
    s32 unkDC;
    s32 unkE0;
    char padE4[0x34];
    s32 unk118;
};

void mOptionMenu__virtual_103(void *arg0, s32 arg1) {
    s8 sp[0x10];
    s32 temp_a0;
    s32 temp_v0;
    s32 temp_v1;

    func_002A7A30(sp);
    temp_v1 = ((struct mOptionMenu__virtual_103_arg0 *)arg0)->unkDC;
    if (temp_v1 != 0) {
        func_0020D6C8(temp_v1, 0);
    }
    temp_a0 = ((struct mOptionMenu__virtual_103_arg0 *)arg0)->unkE0;
    if (temp_a0 != 0) {
        temp_v0 = func_001BA1B0(temp_a0);
        func_004AC4D0(arg0 + 0xF4, 0, temp_v0);
        if (temp_v0 > 0) {
            func_0026AB58(arg0, arg1);
        }
    }
    ((struct mOptionMenu__virtual_103_arg0 *)arg0)->unk118 = 0;
    func_002A75A8(sp, 2);
}
