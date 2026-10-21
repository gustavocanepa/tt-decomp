#include "types.h"

extern void *D_005D9D48;

struct func_0042D838_arg0 {
    char pad0[0x4];
    void *unk4;
    void *unk8;
    void *unkC;
    void *unk10;
    void *unk14;
    void *unk18;
    void *unk1C;
};

extern "C" void func_0042D838(struct func_0042D838_arg0 *arg0) {
    *(void **)(arg0) = 0x0;
    arg0->unk1C = &D_005D9D48;
    arg0->unk4 = 0x0;
    arg0->unk8 = 0x0;
    arg0->unkC = 0x0;
    arg0->unk10 = 0x0;
    arg0->unk14 = 0x0;
    arg0->unk18 = 0x0;
}
