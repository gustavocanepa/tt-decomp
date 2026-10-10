#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_0032A128_arg0_unk184 {
    char pad0[0x6F];
    u8 unk6F;
};
struct func_0032A128_arg0 {
    char pad0[0x184];
    struct func_0032A128_arg0_unk184 *unk184;
};

s32 func_0032A128(struct func_0032A128_arg0 *arg0) {
    return arg0->unk184->unk6F ^ 1;
}
