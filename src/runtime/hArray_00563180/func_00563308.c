#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00563308_arg0 {
    char pad0[0xA0];
    s32 unkA0;
};

s32 func_00563308(struct func_00563308_arg0 *arg0) {
    return arg0->unkA0;
}
