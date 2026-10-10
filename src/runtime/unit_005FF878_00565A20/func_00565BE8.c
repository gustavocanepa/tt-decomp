#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00565BE8_arg0 {
    char pad0[0x4F];
    u8 unk4F;
};

u8 func_00565BE8(struct func_00565BE8_arg0 *arg0) {
    return arg0->unk4F;
}
