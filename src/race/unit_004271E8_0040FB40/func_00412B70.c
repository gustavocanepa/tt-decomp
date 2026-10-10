#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00412B70_arg0 {
    char pad0[0x30];
    s32 unk30;
    s32 unk34;
    s32 unk38;
    s32 unk3C;
    s32 unk40;
    s32 unk44;
    s32 unk48;
};
struct func_00412B70_arg1 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
};

void func_00412B70(struct func_00412B70_arg0 *arg0, struct func_00412B70_arg1 *arg1) {
    arg0->unk30 = (s32) arg1->unk0;
    arg0->unk34 = (s32) arg1->unk4;
    arg0->unk38 = (s32) arg1->unk8;
    arg0->unk3C = (s32) arg1->unkC;
    arg0->unk40 = (s32) arg1->unk10;
    arg0->unk44 = (s32) arg1->unk14;
    arg0->unk48 = (s32) arg1->unk18;
}
