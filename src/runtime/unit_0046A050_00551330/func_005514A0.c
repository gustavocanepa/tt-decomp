#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_005514A0_arg0 {
    char pad0[0xE3E0];
    s32 unkE3E0;
};

s32 func_005514A0(struct func_005514A0_arg0 *arg0) {
    return arg0->unkE3E0;
}
