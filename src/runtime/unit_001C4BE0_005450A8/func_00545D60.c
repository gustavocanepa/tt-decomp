#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00545D60_arg0 {
    char pad0[0x108];
    f32 unk108;
};

f32 func_00545D60(struct func_00545D60_arg0 *arg0) {
    return arg0->unk108;
}
