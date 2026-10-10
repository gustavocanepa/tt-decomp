#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00455BA8_arg0 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    char pad14[0x8];
    s32 unk1C;
    s32 unk20;
};

void func_00455BA8(struct func_00455BA8_arg0 *arg0) {
    arg0->unk0 = 0;
    arg0->unk4 = 0;
    arg0->unk10 = 0;
    arg0->unkC = 0;
    arg0->unk1C = 0;
    arg0->unk8 = 0;
    arg0->unk20 = 0;
}
