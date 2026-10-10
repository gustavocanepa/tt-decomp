#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_002E5D48_arg0 {
    char pad0[0x62C];
    f32 unk62C;
};

f32 func_002E5D48(struct func_002E5D48_arg0 *arg0) {
    return arg0->unk62C;
}
