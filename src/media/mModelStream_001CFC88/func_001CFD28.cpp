#include "types.h"
#define NULL 0

extern char D_005E9210[];

s32 func_001CF388(s32, s32);
void func_001CF7B0(void *);
int func_001D2508(char *, unsigned, const char *, const char *);
void *func_0047DC60(void *, char *, s32 *, s32);
void func_0047DFB0(void *, char *);
s32 malloc(s32);

struct func_001CFD28_arg0 {
    char pad0[0x28];
    s32 unk28;
};

s32 func_001CFD28(struct func_001CFD28_arg0 *arg0, const char *arg1) {
    char sp[0x80];
    s32 sp80[8];
    s32 spA0[4];
    s32 spB0;
    char spB4[0x10];
    s32 temp_v0;
    s32 *pA0;
    s32 sp88;

    if (arg0->unk28 != 0) {
        func_001CF7B0(arg0);
    }
    func_001D2508(sp, 0x80, arg1, D_005E9210);
    func_0047DFB0(sp80, sp);
    sp88 = sp80[2];
    pA0 = spA0;
    pA0[0] = 0;
    pA0[1] = sp88;
    spA0[0] = malloc(sp88);
    func_0047DC60(&spB0, sp, pA0, 1);
    if (spB0 != 0) {
        return 0;
    }
    arg0->unk28 = spA0[0];
    temp_v0 = func_001CF388(spA0[0], spA0[0]);
    if (temp_v0 == 0) {
        func_001CF7B0(arg0);
    }
    return temp_v0;
}
