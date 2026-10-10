#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0020E570_arg0 {
    char pad0[0xB0];
    s32 unkB0;
};

s32 func_0020E570(struct func_0020E570_arg0 *arg0) {
    return ((s32) arg0->unkB0 >> 4) & 1;
}
