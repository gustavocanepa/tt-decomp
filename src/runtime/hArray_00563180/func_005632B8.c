#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_005632B8_arg0 {
    char pad0[0x8C];
    s32 unk8C;
};

s32 func_005632B8(struct func_005632B8_arg0 *arg0) {
    return arg0->unk8C;
}
