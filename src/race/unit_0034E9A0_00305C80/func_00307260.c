#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00307260_arg0 {
    char pad0[0x20A40];
    s32 unk20A40;
};

s32 func_00307260(struct func_00307260_arg0 *arg0) {
    return arg0->unk20A40;
}
