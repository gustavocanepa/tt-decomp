#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00563338_arg0 {
    char pad0[0xAC];
    s32 unkAC;
};

s32 func_00563338(struct func_00563338_arg0 *arg0) {
    return arg0->unkAC;
}
