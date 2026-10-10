#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_004B3448_arg0 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
};

void func_004B3448(struct func_004B3448_arg0 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    arg0->unk10 = arg3;
    arg0->unk0 = 1;
    arg0->unk4 = arg1;
    arg0->unkC = arg2;
    arg0->unk8 = 0;
}
