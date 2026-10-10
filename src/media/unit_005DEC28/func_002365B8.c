#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_002365B8_arg0 {
    char pad0[0xC8];
    s32 unkC8;
};

s32 func_002365B8(struct func_002365B8_arg0 *arg0) {
    return ((s32) arg0->unkC8 >> 4) & 1;
}
