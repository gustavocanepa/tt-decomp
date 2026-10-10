#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_001E7050_arg0 {
    char pad0[0xF0];
    s32 unkF0;
};

s32 func_001E7050(struct func_001E7050_arg0 *arg0) {
    return arg0->unkF0 & 1;
}
