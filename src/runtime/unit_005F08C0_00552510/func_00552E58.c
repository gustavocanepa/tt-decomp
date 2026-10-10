#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00552E58_arg0 {
    char pad0[0xB00];
    s64 unkB00;
    s64 unkB08;
    s64 unkB10;
    s64 unkB18;
    s64 unkB20;
    s64 unkB28;
    s64 unkB30;
    s64 unkB38;
};
struct func_00552E58_arg1 {
    s64 unk0;
    s64 unk8;
    s64 unk10;
    s64 unk18;
    s64 unk20;
    s64 unk28;
    s64 unk30;
    s64 unk38;
};

void func_00552E58(struct func_00552E58_arg0 *arg0, struct func_00552E58_arg1 *arg1) {
    arg0->unkB00 = (s64) arg1->unk0;
    arg0->unkB08 = (s64) arg1->unk8;
    arg0->unkB10 = (s64) arg1->unk10;
    arg0->unkB18 = (s64) arg1->unk18;
    arg0->unkB20 = (s64) arg1->unk20;
    arg0->unkB28 = (s64) arg1->unk28;
    arg0->unkB30 = (s64) arg1->unk30;
    arg0->unkB38 = (s64) arg1->unk38;
}
