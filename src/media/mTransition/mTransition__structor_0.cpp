#include "types.h"

extern void *D_005B3178;
extern "C" void *func_002A7618(void *);

struct mTransition__structor_0_arg0 {
    char pad0[0x4];
    void *unk4;
    char pad8[0x8];
    void *unk10;
    void *unk14;
    void *unk18;
    void *unk1C;
};

extern "C" void *mTransition__structor_0(struct mTransition__structor_0_arg0 *arg0) {
    void *r0 = func_002A7618(arg0);
    arg0->unk4 = &D_005B3178;
    arg0->unk1C = 0x0;
    arg0->unk10 = 0x0;
    arg0->unk14 = (void *)(0x3);
    arg0->unk18 = (void *)(0x3);
    return r0;
}
