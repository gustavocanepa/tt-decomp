#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_005621C0_arg0 {
    char pad0[0x8210];
    s32 unk8210;
};

s32 func_005621C0(struct func_005621C0_arg0 *arg0) {
    return arg0->unk8210;
}
