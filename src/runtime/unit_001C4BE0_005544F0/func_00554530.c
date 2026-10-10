#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00554530_arg0 {
    char pad0[0xE28];
    s32 unkE28;
};

s32 func_00554530(struct func_00554530_arg0 *arg0) {
    return arg0->unkE28;
}
