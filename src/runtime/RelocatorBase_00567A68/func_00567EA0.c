#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00567EA0_arg0 {
    char pad0[0xC];
    s16 unkC;
};

s16 func_00567EA0(struct func_00567EA0_arg0 *arg0) {
    return arg0->unkC;
}
