#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00562238_arg0 {
    char pad0[0x8214];
    s32 unk8214;
};

s32 func_00562238(struct func_00562238_arg0 *arg0) {
    return arg0->unk8214;
}
