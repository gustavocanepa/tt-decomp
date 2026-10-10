#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0031CBE0_arg0 {
    char pad0[0xCC8];
    s32 unkCC8;
};

s32 func_0031CBE0(struct func_0031CBE0_arg0 *arg0) {
    return arg0->unkCC8;
}
