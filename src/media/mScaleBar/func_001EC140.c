#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_001EC140_arg0 {
    char pad0[0xF8];
    s32 unkF8;
};

s32 func_001EC140(struct func_001EC140_arg0 *arg0) {
    return arg0->unkF8;
}
