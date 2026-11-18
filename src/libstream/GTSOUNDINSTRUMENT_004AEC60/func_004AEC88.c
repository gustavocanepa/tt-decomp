#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

extern char D_0059820C[];
struct func_004AEC88_arg0 {
    s32 unk0;
    s32 unk4;
    char pad8[0x4];
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
};

s32 func_004AEC88(struct func_004AEC88_arg0 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 temp_v0;

    arg0->unk0 = arg3;
    arg0->unk4 = arg2;
    arg0->unkC = arg1;
    arg0->unk10 = 0;
    arg0->unk14 = 0;
    temp_v0 = *(s32 *)(s32)D_0059820C;
    arg0->unk18 = temp_v0;
    *(s32 *)(s32)D_0059820C = (s32) arg0;
    return temp_v0;
}
