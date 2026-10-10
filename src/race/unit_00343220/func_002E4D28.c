#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_002E4D28_arg0_unk4 {
    char pad0[0x20A2C];
    s8 unk20A2C;
};
struct func_002E4D28_arg0 {
    char pad0[0x4];
    struct func_002E4D28_arg0_unk4 *unk4;
    char pad8[0x5C8];
    s16 unk5D0;
};

s32 func_002E4D28(struct func_002E4D28_arg0 *arg0) {
    return arg0->unk5D0 + arg0->unk4->unk20A2C;
}
