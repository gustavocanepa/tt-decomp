#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0020D7A8_arg0 {
    char pad0[0xAE];
    s16 unkAE;
};

s32 func_0020D7A8(struct func_0020D7A8_arg0 *arg0) {
    s16 frag0;
    frag0 = arg0->unkAE;
    return frag0 & 1;
}
