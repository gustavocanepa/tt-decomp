#include "types.h"

struct S {
    s32 unk0;
    void *unk4;
    s32 unk8;
};

extern char D_005D86C0;

void func_003F4448(struct S *arg0) {
    arg0->unk8 = 0;
    arg0->unk0 = 0;
    arg0->unk4 = &D_005D86C0;
}
