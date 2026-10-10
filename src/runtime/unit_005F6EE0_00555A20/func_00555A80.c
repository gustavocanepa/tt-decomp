#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_00555A80_arg0_unk4 {
    char pad0[0xB4];
    s32 unkB4;
};
struct func_00555A80_arg0 {
    char pad0[0x4];
    struct func_00555A80_arg0_unk4 *unk4;
};

s32 func_00555A80(struct func_00555A80_arg0 *arg0) {
    return arg0->unk4->unkB4;
}
