#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_0051AE38_arg0_unk10 {
    char pad0[0x78];
    s32 unk78;
};
struct func_0051AE38_arg0 {
    char pad0[0x10];
    struct func_0051AE38_arg0_unk10 *unk10;
};

s32 func_0051AE38(struct func_0051AE38_arg0 *arg0) {
    return arg0->unk10->unk78;
}
