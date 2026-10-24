#include "types.h"

extern "C" float func_002DDCE8(void *arg0, void *arg1);

extern char D_00582AC8[];

struct func_002DFF10_arg0 {
    char pad0[0x10];
    f32 unk10;
    f32 unk14;
    f32 unk18;
};

struct func_002DFF10_entry {
    f32 unk0;
    f32 unk4;
    f32 unk8;
};

struct func_002DFF10_var_s0 {
    char pad0[0xC];
    f32 unkC;
};

extern "C" s32 func_002DFF10(struct func_002DFF10_arg0 *arg0, s32 arg1, void *arg2) {
    f32 temp_f0;
    f32 var_f20;
    s32 var_s1;
    s32 var_s4;
    char *var_s0;

    var_f20 = 0x1.86a0000000000p+16f;
    var_s0 = (char *)D_00582AC8 + (arg1 * 0x50);
    var_s1 = 0;
    var_s4 = -1;
    do {
        temp_f0 = -(func_002DDCE8(arg2, var_s0) + ((struct func_002DFF10_var_s0 *)var_s0)->unkC);
        var_s0 += 0x10;
        if (temp_f0 < var_f20) {
            var_f20 = temp_f0;
            var_s4 = var_s1;
        }
        var_s1 += 1;
    } while (var_s1 < 5);
    if (var_s4 < 0) {
        return -1;
    }
    {
        s32 off = (arg1 * 5 + var_s4) * 0x10;
        struct func_002DFF10_entry *e = (struct func_002DFF10_entry *)((char *)off + (s32)D_00582AC8);
        arg0->unk10 = (f32) (arg0->unk10 + (var_f20 * e->unk0));
        arg0->unk14 = (f32) (arg0->unk14 + (var_f20 * e->unk4));
        arg0->unk18 = (f32) (arg0->unk18 + (var_f20 * e->unk8));
    }
    return var_s4;
}
