#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_002E5CA0_arg0 {
    char pad0[0x580];
    f32 unk580;
    char pad584[0x5];
    u8 unk589;
};

f32 func_002E5CA0(struct func_002E5CA0_arg0 *arg0, u8 *arg1) {
    if (arg1 != NULL) {
        *arg1 = arg0->unk589;
    }
    return arg0->unk580;
}
