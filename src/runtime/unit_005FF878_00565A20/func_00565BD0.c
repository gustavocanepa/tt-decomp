#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00565BD0_arg0 {
    char pad0[0x4C];
    u8 unk4C;
};

u8 func_00565BD0(struct func_00565BD0_arg0 *arg0) {
    return arg0->unk4C;
}
