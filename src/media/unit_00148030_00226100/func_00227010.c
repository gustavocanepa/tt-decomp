#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0024D148();                            /* extern */
void *GT4MC__FileGT4GameData__loadInstance(s32, s32, s32, void *, s32, void *); /* extern */

extern char D_00537A08[];
extern char D_0054D6E8[];
struct func_00227010_temp_v0 {
    s16 unk0;
    char pad2[0x2];
    s32 unk4;
};
struct func_00227010_temp_a0 {
    char pad0[0x4];
    f32 unk4;
    f32 unk8;
    f32 unkC;
};
struct func_00227010_temp_v1 {
    char pad0[0x4];
    f32 unk4;
    f32 unk8;
    f32 unkC;
};
struct func_00227010_temp_a0_2 {
    char pad0[0x4];
    f32 unk4;
    f32 unk8;
    f32 unkC;
};
struct func_00227010_temp_v1_2 {
    char pad0[0x4];
    f32 unk4;
    f32 unk8;
    f32 unkC;
};

struct func_00227010_arg1 {
    char pad0[0x4];
    void *unk4;
};
struct func_00227010_arg0 {
    char pad0[0x8C];
    s32 unk8C;
    f32 unk90;
    char pad94[0xC];
    s32 unkA0;
    f32 unkA4;
};
struct func_00227010_var_a3 {
    char pad0[0x8C];
    s32 unk8C;
    f32 unk90;
    char pad94[0xC];
    s32 unkA0;
    f32 unkA4;
};

void func_00227010(void *arg0, void *arg1) {
    struct func_00227010_temp_a0 *temp_a0;
    struct func_00227010_temp_a0_2 *temp_a0_2;
    struct func_00227010_temp_v0 *temp_v0;
    struct func_00227010_temp_v1 *temp_v1;
    struct func_00227010_temp_v1_2 *temp_v1_2;
    void *var_a3;

    func_0024D148();
    var_a3 = NULL;
    if (arg1 != NULL) {
        temp_v0 = ((struct func_00227010_arg1 *)arg1)->unk4;
        var_a3 = GT4MC__FileGT4GameData__loadInstance(temp_v0->unk4, (s32)D_00537A08, 0, arg1 + temp_v0->unk0, (s32)D_0054D6E8, arg1);
    }
    if (var_a3 != NULL) {
        temp_a0 = arg0 + 0x90;
        if ((arg0 + 0x8C) != (var_a3 + 0x8C)) {
            temp_v1 = var_a3 + 0x90;
            ((struct func_00227010_arg0 *)arg0)->unk8C = (s32) ((struct func_00227010_var_a3 *)var_a3)->unk8C;
            if (temp_a0 != temp_v1) {
                ((struct func_00227010_arg0 *)arg0)->unk90 = (f32) ((struct func_00227010_var_a3 *)var_a3)->unk90;
                temp_a0->unk4 = (f32) temp_v1->unk4;
                temp_a0->unk8 = (f32) temp_v1->unk8;
                temp_a0->unkC = (f32) temp_v1->unkC;
            }
        }
        temp_a0_2 = arg0 + 0xA4;
        if ((arg0 + 0xA0) != (var_a3 + 0xA0)) {
            temp_v1_2 = var_a3 + 0xA4;
            ((struct func_00227010_arg0 *)arg0)->unkA0 = (s32) ((struct func_00227010_var_a3 *)var_a3)->unkA0;
            if (temp_a0_2 != temp_v1_2) {
                ((struct func_00227010_arg0 *)arg0)->unkA4 = (f32) ((struct func_00227010_var_a3 *)var_a3)->unkA4;
                temp_a0_2->unk4 = (f32) temp_v1_2->unk4;
                temp_a0_2->unk8 = (f32) temp_v1_2->unk8;
                temp_a0_2->unkC = (f32) temp_v1_2->unkC;
            }
        }
    }
}
