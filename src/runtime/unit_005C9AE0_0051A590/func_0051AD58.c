#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_0051AD58_arg0_unk10 {
    char pad0[0x6C];
    s32 unk6C;
};
struct func_0051AD58_arg0 {
    char pad0[0x10];
    struct func_0051AD58_arg0_unk10 *unk10;
};

s32 func_0051AD58(struct func_0051AD58_arg0 *arg0) {
    return arg0->unk10->unk6C;
}
