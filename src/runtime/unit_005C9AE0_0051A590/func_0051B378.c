#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0051B378_arg0_unk10 {
    char pad0[0x110C];
    s32 unk110C;
};
struct func_0051B378_arg0 {
    char pad0[0x10];
    struct func_0051B378_arg0_unk10 *unk10;
};

s32 func_0051B378(struct func_0051B378_arg0 *arg0) {
    return arg0->unk10->unk110C;
}
