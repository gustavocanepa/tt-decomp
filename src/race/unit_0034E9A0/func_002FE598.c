#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_002FE598_arg0 {
    char pad0[0x7A2];
    s16 unk7A2;
};

s16 func_002FE598(struct func_002FE598_arg0 *arg0) {
    return arg0->unk7A2;
}
