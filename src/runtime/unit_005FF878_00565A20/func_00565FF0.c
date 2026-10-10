#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00565FF0_arg0 {
    char pad0[0x20];
    s32 unk20;
};

s32 func_00565FF0(struct func_00565FF0_arg0 *arg0) {
    return arg0->unk20;
}
