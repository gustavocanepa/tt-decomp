#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_002FE590_arg0 {
    char pad0[0x7CF];
    s8 unk7CF;
};

s8 func_002FE590(struct func_002FE590_arg0 *arg0) {
    return arg0->unk7CF;
}
