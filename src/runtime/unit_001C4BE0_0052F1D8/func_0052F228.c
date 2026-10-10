#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004F6678(void *, s32, s32);    /* extern */

struct func_0052F228_temp_s2 {
    char pad0[0x4];
    f32 unk4;
    f32 unk8;
    f32 unkC;
};
struct func_0052F228_temp_s0 {
    char pad0[0x4];
    f32 unk4;
    f32 unk8;
    f32 unkC;
};

struct func_0052F228_arg0 {
    s32 unk0;
    f32 unk4;
};
struct func_0052F228_arg1 {
    char pad0[0x14C];
    s32 unk14C;
    f32 unk150;
};

void *func_0052F228(void *arg0, void *arg1) {
    struct func_0052F228_temp_s0 *temp_s0;
    struct func_0052F228_temp_s2 *temp_s2;

    temp_s2 = arg0 + 4;
    temp_s0 = arg1 + 0x150;
    ((struct func_0052F228_arg0 *)arg0)->unk0 = (s32) ((struct func_0052F228_arg1 *)arg1)->unk14C;
    func_004F6678(temp_s2, 0, 0x10);
    ((struct func_0052F228_arg0 *)arg0)->unk4 = (f32) ((struct func_0052F228_arg1 *)arg1)->unk150;
    temp_s2->unk4 = (f32) temp_s0->unk4;
    temp_s2->unk8 = (f32) temp_s0->unk8;
    temp_s2->unkC = (f32) temp_s0->unkC;
    return arg0;
}
