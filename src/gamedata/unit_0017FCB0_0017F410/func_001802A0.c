#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_001802A0_arg0_unk10 {
    char pad0[0x108];
    s32 unk108;
};
struct func_001802A0_arg0 {
    char pad0[0x10];
    struct func_001802A0_arg0_unk10 *unk10;
};

s32 func_001802A0(struct func_001802A0_arg0 *arg0) {
    return arg0->unk10->unk108;
}
