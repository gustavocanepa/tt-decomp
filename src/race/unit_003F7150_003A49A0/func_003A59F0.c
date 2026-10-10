#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_003A59F0_arg0 {
    char pad0[0x23924];
    u8 unk23924;
};

u8 func_003A59F0(struct func_003A59F0_arg0 *arg0) {
    return arg0->unk23924;
}
