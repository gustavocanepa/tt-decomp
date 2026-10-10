#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct hFileIO {
    s32 unk0;
    void * unk4;
    s32 unk8;
    void * unkC;
    s32 unk10;
    void * unk14;
    char unk_18[0xD0];
    s32 unkE8;
    s32 unkEC;
    s32 unkF0;
    s32 unkF4;
    s32 unkF8;
};
char * func_0050F0F0(void *);
struct func_002998B0_arg1 {
    char pad0[0x14];
    s8 *unk14;
};
struct func_002998B0_temp_a1 {
    char pad0[0x8];
    s32 unk8;
    s32 unkC;
};

s32 *func_002998B0(struct hFileIO *arg0, struct func_002998B0_arg1 *arg1) {
    s8 *temp_v0;
    s8 *var_a2;
    struct func_002998B0_temp_a1 *temp_a1;

    temp_v0 = arg1->unk14;
    temp_a1 = temp_v0 - 0x10;
    var_a2 = temp_v0;
    if (temp_a1->unkC != 0) {
        var_a2 = func_0050F0F0(temp_a1);
    } else {
        temp_a1->unk8 = (s32) (temp_a1->unk8 + 1);
    }
    arg0->unk0 = (s32) var_a2;
    return &arg0->unk0;
}
