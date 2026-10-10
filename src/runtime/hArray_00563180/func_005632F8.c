#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_005632F8_arg0 {
    char pad0[0x9C];
    s32 unk9C;
};

s32 func_005632F8(struct func_005632F8_arg0 *arg0) {
    return arg0->unk9C;
}
