#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_005619B0_arg0 {
    char pad0[0x28];
    s8 unk28;
};

s32 func_005619B0(struct func_005619B0_arg0 *arg0) {
    return arg0->unk28 != 0;
}
