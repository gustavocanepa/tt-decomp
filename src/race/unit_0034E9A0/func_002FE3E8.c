#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_002FE3E8_arg0 {
    char pad0[0x58A];
    s8 unk58A;
};

s32 func_002FE3E8(struct func_002FE3E8_arg0 *arg0) {
    return arg0->unk58A == 0;
}
