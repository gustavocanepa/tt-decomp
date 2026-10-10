#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_005764E8_arg0 {
    char pad0[0x1C];
    s32 unk1C;
    s32 unk20;
};

s32 func_005764E8(struct func_005764E8_arg0 *arg0) {
    return arg0->unk20 - arg0->unk1C;
}
