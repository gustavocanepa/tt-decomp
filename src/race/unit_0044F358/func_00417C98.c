#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00417C98_arg0 {
    char pad0[0x120];
    f32 unk120;
};

f32 func_00417C98(struct func_00417C98_arg0 *arg0) {
    return arg0->unk120;
}
