#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_00566088_arg0_unk18 {
    char pad0[0x4];
    s32 unk4;
};
struct func_00566088_arg0 {
    char pad0[0x18];
    struct func_00566088_arg0_unk18 *unk18;
};

s32 func_00566088(struct func_00566088_arg0 *arg0) {
    return arg0->unk18->unk4;
}
