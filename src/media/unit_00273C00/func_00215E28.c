#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

void func_0041F840(void *);
s32 func_0041F9B0(void *);
void func_0041FAC8(s32, s32 *, s32, s32);
struct func_00215E28_arg0_unk8 {
    char pad0[0x7C];
    s32 *unk7C;
};
struct func_00215E28_arg0 {
    char pad0[0x8];
    struct func_00215E28_arg0_unk8 *unk8;
    s32 unkC;
};

s32 func_00215E28(struct func_00215E28_arg0 *arg0, void *arg1, s32 arg2) {
    s32 *temp_a1;
    s32 var_v0;
    var_v0 = func_0041F9B0(arg1);
    if (var_v0 != 0) {
        arg0->unkC = arg2;
        arg0->unk8 = arg1;
        func_0041F840(arg1);
        temp_a1 = arg0->unk8->unk7C;
        func_0041FAC8(*temp_a1, temp_a1, 0, 0);
        var_v0 = 1;
    }
    return var_v0;
}
