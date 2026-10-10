#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00554470_arg0 {
    char pad0[0xE0C];
    s32 unkE0C;
};

s32 func_00554470(struct func_00554470_arg0 *arg0) {
    return arg0->unkE0C;
}
