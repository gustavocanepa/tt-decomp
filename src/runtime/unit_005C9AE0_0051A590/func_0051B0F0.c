#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_0051B0F0_arg0_unk10 {
    char pad0[0x10D4];
    s32 unk10D4;
};
struct func_0051B0F0_arg0 {
    char pad0[0x10];
    struct func_0051B0F0_arg0_unk10 *unk10;
};

s32 func_0051B0F0(struct func_0051B0F0_arg0 *arg0) {
    return arg0->unk10->unk10D4;
}
