#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0051D980_arg0 {
    char pad0[0xC0];
    s32 unkC0;
};

s32 func_0051D980(struct func_0051D980_arg0 *arg0) {
    return arg0->unkC0 == 2;
}
