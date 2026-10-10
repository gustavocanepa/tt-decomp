#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_0051B2F8_arg0_unk10 {
    char pad0[0x10FC];
    s32 unk10FC;
};
struct func_0051B2F8_arg0 {
    char pad0[0x10];
    struct func_0051B2F8_arg0_unk10 *unk10;
};

s32 func_0051B2F8(struct func_0051B2F8_arg0 *arg0) {
    return arg0->unk10->unk10FC;
}
