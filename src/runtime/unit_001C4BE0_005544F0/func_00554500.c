#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00554500_arg0 {
    char pad0[0xE08];
    s32 unkE08;
};

s32 func_00554500(struct func_00554500_arg0 *arg0) {
    return arg0->unkE08;
}
