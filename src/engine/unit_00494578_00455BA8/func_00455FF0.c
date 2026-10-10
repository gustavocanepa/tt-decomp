#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00455FF0_arg0 {
    s32 unk0;
    s32 unk4;
    char pad8[0x4];
    s32 unkC;
    s32 unk10;
    char pad14[0x4];
    s32 unk18;
    s32 unk1C;
};

s32 func_00455FF0(struct func_00455FF0_arg0 *arg0, s32 arg1) {
    arg0->unk10 = arg1;
    arg0->unkC = (s32) (arg0->unk0 + arg1);
    if (arg0->unk4 < arg1) {
        arg0->unk18 = 1;
        arg0->unk1C = 1;
        return 0;
    }
    return 1;
}
