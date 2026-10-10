#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00370480_arg0 {
    char pad0[0x12C];
    s32 unk12C;
};

s32 func_00370480(struct func_00370480_arg0 *arg0) {
    return arg0->unk12C;
}
