#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0025DC88_arg0 {
    char pad0[0x6C];
    f32 unk6C;
};

f32 func_0025DC88(struct func_0025DC88_arg0 *arg0) {
    return 0x1.0000000000000p+0f / arg0->unk6C;
}
