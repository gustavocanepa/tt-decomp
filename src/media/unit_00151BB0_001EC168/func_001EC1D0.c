#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_001EC1D0_arg0 {
    char pad0[0x110];
    f32 unk110;
};

f32 func_001EC1D0(struct func_001EC1D0_arg0 *arg0) {
    return arg0->unk110;
}
