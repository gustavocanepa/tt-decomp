#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0053B478_arg0 {
    char pad0[0xC8];
    s32 unkC8;
};

s32 func_0053B478(struct func_0053B478_arg0 *arg0) {
    return ((s32) arg0->unkC8 >> 6) & 1;
}
