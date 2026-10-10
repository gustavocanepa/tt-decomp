#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0045EDE8();                            /* extern */
s32 func_00460720(s32, s32, s32);               /* extern */

struct func_0045EBA8_temp_s0 {
    char pad0[0x4];
    s32 unk4;
    s32 unk8;
    char padC[0x8];
    s32 unk14;
};

struct func_0045EBA8_arg0 {
    char pad0[0x30];
    s32 unk30;
};

s32 func_0045EBA8(void *arg0) {
    struct func_0045EBA8_temp_s0 *temp_s0;

    temp_s0 = arg0 + 0x10;
    if (temp_s0->unk8 != 0) {
        func_0045EDE8();
        func_00460720(((struct func_0045EBA8_arg0 *)arg0)->unk30, temp_s0->unk14, temp_s0->unk4);
    }
}
