#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00564BF8_arg0 {
    char pad0[0x84];
    s32 unk84;
};

s32 func_00564BF8(struct func_00564BF8_arg0 *arg0) {
    return arg0->unk84;
}
