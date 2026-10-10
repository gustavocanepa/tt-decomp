#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 GT4Model__BinStreamReader__read8u(s32);                             /* extern */
s32 GT4Model__BinStreamReader__readArray(s32, void *, s32);        /* extern */
s32 func_004242C0(void *);                      /* extern */
s32 func_004243E0(void *, s32);                 /* extern */

struct func_002DD060_arg0 {
    char pad0[0x34];
    f32 unk34;
    f32 unk38;
    s32 unk3C;
    f32 unk40;
};

void func_002DD060(void *arg0, s32 arg1) {
    s8 sp[0x10];
    s32 temp_s0;

    func_004242C0(sp);
    temp_s0 = GT4Model__BinStreamReader__read8u(arg1);
    GT4Model__BinStreamReader__readArray(arg1, arg0, 0x24);
    GT4Model__BinStreamReader__readArray(arg1, arg0 + 0x24, 0x10);
    if (temp_s0 > 0) {
        GT4Model__BinStreamReader__readArray(arg1, arg0 + 0x34, 4);
        GT4Model__BinStreamReader__readArray(arg1, arg0 + 0x38, 4);
        GT4Model__BinStreamReader__readArray(arg1, arg0 + 0x3C, 4);
        GT4Model__BinStreamReader__readArray(arg1, arg0 + 0x40, 4);
    } else {
        ((struct func_002DD060_arg0 *)arg0)->unk40 = 5500.0f;
        ((struct func_002DD060_arg0 *)arg0)->unk34 = 5.0f;
        ((struct func_002DD060_arg0 *)arg0)->unk38 = 0.008333333f;
        ((struct func_002DD060_arg0 *)arg0)->unk3C = 0;
    }
    func_004243E0(sp, arg1);
}
