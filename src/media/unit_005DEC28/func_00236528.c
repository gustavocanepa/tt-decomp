#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_00236528_arg0 {
    char pad0[0xC8];
    s32 unkC8;
};

s32 func_00236528(struct func_00236528_arg0 *arg0) {
    return arg0->unkC8 & 1;
}
