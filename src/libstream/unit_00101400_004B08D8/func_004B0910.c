#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_004B0910_arg0 {
    s64 unk0;
    s32 unk8;
    s32 unkC;
    char pad10[0x10];
    s16 unk20;
};

void func_004B0910(struct func_004B0910_arg0 *arg0) {
    arg0->unk0 = 0;
    arg0->unk20 = -0x20;
    arg0->unk8 = 0;
    arg0->unkC = 0;
}
