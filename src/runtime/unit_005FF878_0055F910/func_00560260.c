#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00560260_arg0 {
    char pad0[0x1D0];
    s32 unk1D0;
};

s32 func_00560260(struct func_00560260_arg0 *arg0) {
    return arg0->unk1D0;
}
