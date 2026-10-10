#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_005184D0_arg0 {
    char pad0[0x190];
    s32 unk190;
};

s32 func_005184D0(struct func_005184D0_arg0 *arg0) {
    return arg0->unk190;
}
