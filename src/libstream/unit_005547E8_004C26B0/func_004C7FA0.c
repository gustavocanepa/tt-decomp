#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_004C7FA0_arg0 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
};

void func_004C7FA0(struct func_004C7FA0_arg0 *arg0) {
    arg0->unk4 = 0;
    arg0->unkC = 1;
    arg0->unk0 = 0;
    arg0->unk8 = 0;
}
