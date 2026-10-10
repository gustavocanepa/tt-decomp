#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

void func_002F4AB0(void *, s32, s32, f32); /* extern */

struct func_00426FB0_arg0 {
    char pad0[0x44C];
    f32 unk44C;
    char pad450[0x94];
    s32 unk4E4;
    f32 unk4E8;
    s32 unk4EC;
    f32 unk4F0;
};
struct func_00426FB0_arg1 {
    char pad0[0x730];
    f32 unk730;
};

void func_00426FB0(struct func_00426FB0_arg0 *arg0, struct func_00426FB0_arg1 *arg1) {
    f32 temp_f12;
    f32 var_f12;
    f32 var_f2;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v0_3;

    temp_f12 = arg0->unk44C;
    if ((temp_f12 > 0x0.0p+0f) && ((arg0->unk4EC == 0) || (arg0->unk4F0 < temp_f12))) {
        var_f12 = 0x1.0000000000000p+1f * temp_f12;
        if (var_f12 > 0x1.0000000000000p+0f) {
            var_f12 = 0x1.0000000000000p+0f;
        }
        func_002F4AB0(arg1, -1, -1, var_f12);
        var_f2 = arg0->unk44C;
        arg0->unk4EC = 0x3C;
        arg0->unk4F0 = var_f2;
    } else {
        func_002F4AB0(arg1, -1, -1, 0x0.0p+0f);
        temp_v0 = arg0->unk4EC - 1;
        var_f2 = arg0->unk44C;
        arg0->unk4EC = (s32) ((temp_v0 < 0) ? 0 : temp_v0);
        arg0->unk4F0 = (f32) (arg0->unk4F0 * 0x1.f5c28e0000000p-1f);
    }
    if (var_f2 > 0x1.0000000000000p+0f) {
        arg0->unk44C = 0x1.0000000000000p+0f;
        var_f2 = 0x1.0000000000000p+0f;
    }
    temp_v0_2 = arg0->unk4E4;
    if (temp_v0_2 > 0) {
        temp_v0_3 = temp_v0_2 - 1;
        if (arg0->unk4E8 < var_f2) {
            if (arg1->unk730 < var_f2) {
                arg1->unk730 = var_f2;
                var_f2 = arg0->unk44C;
            }
            arg0->unk4E8 = var_f2;
            arg0->unk4E4 = 0x17;
            return;
        }
        arg0->unk4E4 = temp_v0_3;
        if (temp_v0_3 == 0) {
            arg1->unk730 = 0x0.0p+0f;
        }
    } else if (var_f2 > 0x0.0p+0f) {
        arg1->unk730 = var_f2;
        arg0->unk4E4 = 0x17;
        arg0->unk4E8 = (f32) arg0->unk44C;
    }
}
