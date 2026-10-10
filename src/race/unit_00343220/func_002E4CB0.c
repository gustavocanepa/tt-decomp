#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_002E4CB0_arg0 {
    char pad0[0x5D0];
    s16 unk5D0;
};

s16 func_002E4CB0(struct func_002E4CB0_arg0 *arg0) {
    return arg0->unk5D0;
}
