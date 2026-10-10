#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_004021F8_arg0 {
    char pad0[0x23404];
    s32 unk23404;
};

void func_004021F8(struct func_004021F8_arg0 *arg0, s32 arg1) {
    arg0->unk23404 = arg1;
}
