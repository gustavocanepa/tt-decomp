#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00564250_arg0 {
    char pad0[0x4];
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
};

void func_00564250(struct func_00564250_arg0 *arg0, s32 arg1, s32 arg2) {
    arg0->unk10 = 0;
    arg0->unk8 = arg2;
    arg0->unkC = arg2;
    arg0->unk4 = arg1;
}
