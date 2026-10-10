#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00562D28_arg0 {
    char pad0[0x115C];
    s32 unk115C;
};

s32 func_00562D28(struct func_00562D28_arg0 *arg0) {
    return arg0->unk115C;
}
