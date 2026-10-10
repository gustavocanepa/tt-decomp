#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_002E5C58_arg0 {
    char pad0[0x719];
    u8 unk719;
};

u8 func_002E5C58(struct func_002E5C58_arg0 *arg0) {
    return arg0->unk719;
}
