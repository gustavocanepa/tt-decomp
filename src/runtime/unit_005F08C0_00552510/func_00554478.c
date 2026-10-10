#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00554478_arg0 {
    char pad0[0xE14];
    s32 unkE14;
};

s32 func_00554478(struct func_00554478_arg0 *arg0) {
    return arg0->unkE14 > 0;
}
