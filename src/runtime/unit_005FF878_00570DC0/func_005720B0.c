#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_005720B0_arg0 {
    s32 unk0;
    s32 unk4;
    s8 unk8;
    char pad9[0x3];
    s32 unkC;
};

void func_005720B0(struct func_005720B0_arg0 *arg0, s32 arg1) {
    arg0->unk0 = arg1;
    arg0->unk8 = 0;
    arg0->unk4 = arg1;
    arg0->unkC = 0;
}
