#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00561C38_arg0 {
    char pad0[0xFC];
    s32 unkFC;
};

s32 func_00561C38(struct func_00561C38_arg0 *arg0) {
    return arg0->unkFC;
}
