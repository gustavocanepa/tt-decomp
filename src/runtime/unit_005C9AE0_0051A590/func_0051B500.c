#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0051B500_arg0_unk10 {
    char pad0[0x171C];
    s32 unk171C;
};
struct func_0051B500_arg0 {
    char pad0[0x10];
    struct func_0051B500_arg0_unk10 *unk10;
};

s32 func_0051B500(struct func_0051B500_arg0 *arg0) {
    return arg0->unk10->unk171C;
}
