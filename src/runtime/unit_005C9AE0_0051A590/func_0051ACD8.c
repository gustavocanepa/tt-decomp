#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_0051ACD8_arg0_unk10 {
    char pad0[0x64];
    s32 unk64;
};
struct func_0051ACD8_arg0 {
    char pad0[0x10];
    struct func_0051ACD8_arg0_unk10 *unk10;
};

s32 func_0051ACD8(struct func_0051ACD8_arg0 *arg0) {
    return arg0->unk10->unk64;
}
