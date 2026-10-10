#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00563318_arg0 {
    char pad0[0xA4];
    s32 unkA4;
};

s32 func_00563318(struct func_00563318_arg0 *arg0) {
    return arg0->unkA4;
}
