#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_002E9548_arg0 {
    char pad0[0x23902];
    u8 unk23902;
};

u8 func_002E9548(struct func_002E9548_arg0 *arg0) {
    return arg0->unk23902;
}
