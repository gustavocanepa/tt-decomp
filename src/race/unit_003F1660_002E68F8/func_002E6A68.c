#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_002E6A68_arg0 {
    char pad0[0x118];
    f32 unk118;
};

f32 func_002E6A68(struct func_002E6A68_arg0 *arg0) {
    return arg0->unk118;
}
