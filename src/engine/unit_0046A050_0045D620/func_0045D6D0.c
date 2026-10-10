#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

void *func_004F4E58(s32, void *, s32, s32, void *);
void func_0045D6B8();
struct func_0045D6D0_arg0 {
    char pad0[0xC];
    s32 unkC;
};
struct func_0045D6D0_r {
    char pad0[0x4];
    s32 unk4;
};

s32 func_0045D6D0(void *arg0, s32 arg1) {
    void *r = func_004F4E58(arg1, (s8 *)arg0 + 0x10, ((struct func_0045D6D0_arg0 *)arg0)->unkC, 8, (void *)func_0045D6B8);
    if (r != 0) return ((struct func_0045D6D0_r *)r)->unk4;
    return 0;
}
