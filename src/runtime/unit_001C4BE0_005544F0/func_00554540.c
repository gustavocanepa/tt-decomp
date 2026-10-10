#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00554540_arg0 {
    char pad0[0xE2C];
    s32 unkE2C;
};

s32 func_00554540(struct func_00554540_arg0 *arg0) {
    return arg0->unkE2C;
}
