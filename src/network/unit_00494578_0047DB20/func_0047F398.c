#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_0047F398_arg0_unk4 {
    char pad0[0x38];
    s32 unk38;
};
struct func_0047F398_arg0 {
    char pad0[0x4];
    struct func_0047F398_arg0_unk4 *unk4;
};

s32 func_0047F398(struct func_0047F398_arg0 *arg0) {
    return arg0->unk4->unk38;
}
