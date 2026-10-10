#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_005544B0_arg0 {
    char pad0[0xDA0];
    s32 unkDA0;
};

s32 func_005544B0(struct func_005544B0_arg0 *arg0) {
    return arg0->unkDA0;
}
