#include "types.h"
#define NULL 0

struct func_002B5040_temp {
    char pad0[0x30];
    s32 unk30;
};

struct func_002B5040_arg0 {
    char pad0[0x8];
    s32 unk8;
};

struct func_002B5040_arg1 {
    char pad0[0x24];
    struct func_002B5040_temp *unk24;
    s32 unk28;
};

extern "C" void mJump__execute(struct func_002B5040_arg0 *arg0, struct func_002B5040_arg1 *arg1) {
    s32 var_v0;
    s32 idx;
    s32 scaled;
    struct func_002B5040_temp *temp_v1;

    idx = arg0->unk8;
    temp_v1 = arg1->unk24;
    scaled = idx * 4;
    if (temp_v1 != NULL) {
        var_v0 = temp_v1->unk30 + scaled;
    } else {
        var_v0 = 0;
    }
    arg1->unk28 = var_v0;
}
