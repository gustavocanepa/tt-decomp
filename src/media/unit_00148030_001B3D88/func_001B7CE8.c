#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_002A7618();                            /* extern */
s32 func_004F6678(void *, s32, s32);    /* extern */

extern char D_005AE7C0[];
struct func_001B7CE8_temp_s1 {
    char pad0[0x4];
    f32 unk4;
    f32 unk8;
    f32 unkC;
};
struct func_001B7CE8_temp_s0 {
    char pad0[0x4];
    f32 unk4;
    f32 unk8;
    f32 unkC;
};

struct func_001B7CE8_arg0 {
    char pad0[0x4];
    s32 unk4;
    char pad8[0x8];
    s32 unk10;
    f32 unk14;
};
struct func_001B7CE8_arg1 {
    s32 unk0;
    f32 unk4;
};

void func_001B7CE8(void *arg0, void *arg1) {
    struct func_001B7CE8_temp_s0 *temp_s0;
    struct func_001B7CE8_temp_s1 *temp_s1;

    func_002A7618();
    temp_s1 = arg0 + 0x14;
    temp_s0 = arg1 + 4;
    ((struct func_001B7CE8_arg0 *)arg0)->unk4 = (s32)D_005AE7C0;
    ((struct func_001B7CE8_arg0 *)arg0)->unk10 = (s32) ((struct func_001B7CE8_arg1 *)arg1)->unk0;
    func_004F6678(temp_s1, 0, 0x10);
    ((struct func_001B7CE8_arg0 *)arg0)->unk14 = (f32) ((struct func_001B7CE8_arg1 *)arg1)->unk4;
    temp_s1->unk4 = (f32) temp_s0->unk4;
    temp_s1->unk8 = (f32) temp_s0->unk8;
    temp_s1->unkC = (f32) temp_s0->unkC;
}
