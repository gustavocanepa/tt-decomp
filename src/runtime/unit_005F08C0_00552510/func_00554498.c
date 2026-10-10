#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00554498_arg0 {
    char pad0[0xE1C];
    s32 unkE1C;
};

s32 func_00554498(struct func_00554498_arg0 *arg0) {
    return arg0->unkE1C;
}
