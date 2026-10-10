#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00481DE8(s32, s32, s32, s32, s32); /* extern */
s32 func_00484078();                                /* extern */

extern char D_00605B40[];
struct func_00483FC8_arg0 {
    char pad0[0x4];
    s32 unk4;
    char pad8[0x8];
    s32 unk10;
    s32 unk14;
};

void func_00483FC8(struct func_00483FC8_arg0 *arg0) {
    s32 temp_v0;
    s32 temp_v1;

    temp_v0 = func_00484078();
    temp_v1 = arg0->unk10;
    if (temp_v0 < temp_v1) {
        func_00481DE8(arg0->unk14, arg0->unk4, temp_v0, temp_v1 - temp_v0, (s32)D_00605B40);
        arg0->unk10 = temp_v0;
        return;
    }
    if (temp_v1 < temp_v0) {
        func_00481DE8(arg0->unk14, arg0->unk4, temp_v1, temp_v0 - temp_v1, (s32)D_00605B40);
    }
}
