#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00544238_arg0 {
    char pad0[0x87C];
    s32 unk87C;
};

s32 func_00544238(struct func_00544238_arg0 *arg0) {
    return arg0->unk87C;
}
