#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00552EA8_arg0 {
    char pad0[0xB40];
    s64 unkB40;
    s64 unkB48;
    s64 unkB50;
    s64 unkB58;
    s64 unkB60;
    s64 unkB68;
    s64 unkB70;
    s64 unkB78;
};
struct func_00552EA8_arg1 {
    s64 unk0;
    s64 unk8;
    s64 unk10;
    s64 unk18;
    s64 unk20;
    s64 unk28;
    s64 unk30;
    s64 unk38;
};

void func_00552EA8(struct func_00552EA8_arg0 *arg0, struct func_00552EA8_arg1 *arg1) {
    arg0->unkB40 = (s64) arg1->unk0;
    arg0->unkB48 = (s64) arg1->unk8;
    arg0->unkB50 = (s64) arg1->unk10;
    arg0->unkB58 = (s64) arg1->unk18;
    arg0->unkB60 = (s64) arg1->unk20;
    arg0->unkB68 = (s64) arg1->unk28;
    arg0->unkB70 = (s64) arg1->unk30;
    arg0->unkB78 = (s64) arg1->unk38;
}
