#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_0051AD68_arg0_unk10 {
    char pad0[0x6C];
    s32 unk6C;
};
struct func_0051AD68_arg0 {
    char pad0[0x10];
    struct func_0051AD68_arg0_unk10 *unk10;
};

void func_0051AD68(struct func_0051AD68_arg0 *arg0, s32 arg1) {
    arg0->unk10->unk6C = arg1;
}
