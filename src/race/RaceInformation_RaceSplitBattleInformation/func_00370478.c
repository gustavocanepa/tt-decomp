#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00370478_arg0 {
    char pad0[0x128];
    s32 unk128;
};

s32 func_00370478(struct func_00370478_arg0 *arg0) {
    return arg0->unk128;
}
