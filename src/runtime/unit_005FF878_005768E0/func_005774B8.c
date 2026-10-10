#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_005774B8_arg0 {
    char pad0[0x8];
    s32 unk8;
    char padC[0x8];
    s32 unk14;
};

s32 func_005774B8(struct func_005774B8_arg0 *arg0) {
    return arg0->unk14 - arg0->unk8;
}
