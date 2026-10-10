#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_004021E8_arg0 {
    char pad0[0x23404];
    s32 unk23404;
};

s32 func_004021E8(struct func_004021E8_arg0 *arg0) {
    return arg0->unk23404;
}
