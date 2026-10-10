#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00562D68_arg0 {
    char pad0[0x116C];
    s32 unk116C;
};

s32 func_00562D68(struct func_00562D68_arg0 *arg0) {
    return arg0->unk116C;
}
