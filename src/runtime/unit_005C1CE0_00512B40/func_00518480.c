#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00518480_arg0 {
    char pad0[0x18C];
    s32 unk18C;
};

s32 func_00518480(struct func_00518480_arg0 *arg0) {
    return arg0->unk18C;
}
