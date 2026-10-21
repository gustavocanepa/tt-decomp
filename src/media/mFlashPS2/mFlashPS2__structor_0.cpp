#include "types.h"

extern void *D_005B3EA8;
extern "C" void *func_002345D8(void *);

struct mFlashPS2__structor_0_arg0 {
    char pad0[0x4];
    void *unk4;
    char pad8[0x4];
    void *unkC;
    void *unk10;
    void *unk14;
    void *unk18;
    void *unk1C;
};

extern "C" void *mFlashPS2__structor_0(struct mFlashPS2__structor_0_arg0 *arg0) {
    void *r0 = func_002345D8(arg0);
    arg0->unkC = 0x0;
    arg0->unk4 = &D_005B3EA8;
    arg0->unk10 = 0x0;
    arg0->unk14 = 0x0;
    arg0->unk18 = 0x0;
    arg0->unk1C = 0x0;
    return r0;
}
