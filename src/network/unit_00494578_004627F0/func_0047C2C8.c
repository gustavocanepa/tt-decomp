#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0047C2C8_arg0 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
};

void func_0047C2C8(struct func_0047C2C8_arg0 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 temp_a3;
    s32 temp_v0;
    s32 var_a4;
    s32 var_a5;
    s32 var_v1;
    u32 var_a1;

    var_v1 = arg0->unk0;
    if (var_v1 == 0) {
        arg0->unk0 = arg1;
        var_v1 = arg1;
    }
    temp_a3 = arg3 & ~3;
    var_a4 = arg2;
    var_a1 = (arg2 + temp_a3) - 4;
    var_a5 = 0;
    if (var_a1 >= (u32) (arg2 + var_v1)) {
        do {
            *(s32 *)var_a1 = -4;
            var_a1 -= 4;
            temp_v0 = arg0->unk0;
            var_a4 += temp_v0;
            var_a5 += 1;
        } while (var_a1 >= (u32) (var_a4 + temp_v0));
    }
    arg0->unk4 = arg2;
    arg0->unk8 = temp_a3;
    arg0->unkC = var_a5;
}
