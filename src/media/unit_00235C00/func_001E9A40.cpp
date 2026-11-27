#include "types.h"

extern "C" void func_0052A718(void *self, struct func_001E9A40_node *x);

struct func_001E9A40_node {
    s32 unk0;
    struct func_001E9A40_node *unk4;
    struct func_001E9A40_node *unk8;
    struct func_001E9A40_node *unkC;
};

struct func_001E9A40_ctl {
    s32 unk0;
    struct func_001E9A40_node *unk4;
    struct func_001E9A40_node *unk8;
};

extern "C" void func_001E9A40(char *arg0) {
    struct func_001E9A40_ctl *c = (struct func_001E9A40_ctl *)(arg0 + 0x118);

    if (c->unk8 != 0) {
        func_0052A718(c, c->unk4->unk4);
        c->unk4->unk8 = c->unk4;
        c->unk4->unk4 = 0;
        c->unk4->unkC = c->unk4;
        c->unk8 = 0;
    }
}
