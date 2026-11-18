#include "types.h"

extern void *D_005C47F8;
extern "C" void *func_002A7618(void *);

struct func_0029E8B0_arg0 {
    char pad0[0x4];
    void *unk4;
    char pad8[0x8];
    void *unk10;
};

extern "C" void *func_0029E8B0(struct func_0029E8B0_arg0 *arg0, s32 arg1) {
    void *r0 = func_002A7618(arg0);
    arg0->unk4 = &D_005C47F8;
    arg0->unk10 = (void *)(arg1);
    return r0;
}
