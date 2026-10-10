#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_004C81C8_temp_v1 {
    char pad0[0x4];
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
};

struct func_004C81C8_arg0 {
    char pad0[0x24];
    s8 unk24;
    char pad25[0xAB];
    s32 unkD0;
};

void func_004C81C8(void *arg0, s32 arg1) {
    s32 var_a1;
    s8 var_a2;
    struct func_004C81C8_temp_v1 *temp_v1;

    var_a1 = arg1;
    temp_v1 = arg0 + 0xD0;
    if (var_a1 != 0) {
        var_a1 *= 0x708;
    }
    var_a2 = 0;
    temp_v1->unk8 = var_a1;
    temp_v1->unk10 = 0;
    temp_v1->unkC = 0;
    if ((temp_v1->unk4 != 0) && (var_a1 != 0)) {
        var_a2 = ((struct func_004C81C8_arg0 *)arg0)->unkD0 != 0;
    }
    ((struct func_004C81C8_arg0 *)arg0)->unk24 = var_a2;
}
