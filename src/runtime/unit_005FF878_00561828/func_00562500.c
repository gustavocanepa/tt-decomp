#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00562500_arg0 {
    char pad0[0x171C];
    s32 unk171C;
};

s32 func_00562500(struct func_00562500_arg0 *arg0) {
    return arg0->unk171C;
}
