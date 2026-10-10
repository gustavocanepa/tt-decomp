#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_005260B0_temp_a3 {
    char pad0[0x4];
    f32 unk4;
    f32 unk8;
    f32 unkC;
};
struct func_005260B0_temp_v1 {
    char pad0[0x4];
    f32 unk4;
    f32 unk8;
    f32 unkC;
};

struct func_005260B0_var_a0 {
    s32 unk0;
    f32 unk4;
};
struct func_005260B0_arg2 {
    s32 unk0;
    f32 unk4;
};

void func_005260B0(void *arg0, s32 arg1, void *arg2) {
    struct func_005260B0_temp_a3 *temp_a3;
    struct func_005260B0_temp_v1 *temp_v1;
    void *var_a0;

    var_a0 = arg0;
    if (var_a0 != arg1) {
        do {
            temp_a3 = var_a0 + 4;
            if (var_a0 != arg2) {
                temp_v1 = arg2 + 4;
                ((struct func_005260B0_var_a0 *)var_a0)->unk0 = (s32) ((struct func_005260B0_arg2 *)arg2)->unk0;
                if (temp_a3 != temp_v1) {
                    ((struct func_005260B0_var_a0 *)var_a0)->unk4 = (f32) ((struct func_005260B0_arg2 *)arg2)->unk4;
                    temp_a3->unk4 = (f32) temp_v1->unk4;
                    temp_a3->unk8 = (f32) temp_v1->unk8;
                    temp_a3->unkC = (f32) temp_v1->unkC;
                }
            }
            var_a0 += 0x14;
        } while (var_a0 != arg1);
    }
}
