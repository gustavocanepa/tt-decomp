#include "types.h"

extern void *D_005C7A68;
extern "C" void *func_002BC190(void *);

struct func_002C13E8_arg0 {
    char pad0[0x4];
    void *unk4;
    char pad8[0x4];
    void *unkC;
};

extern "C" void *func_002C13E8(struct func_002C13E8_arg0 *arg0, s32 arg1, s32 arg2) {
    void *r0 = func_002BC190(arg0);
    arg0->unk4 = &D_005C7A68;
    arg0->unkC = (void *)(arg2);
    return r0;
}
