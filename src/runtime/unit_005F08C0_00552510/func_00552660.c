#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00552660_arg0 {
    char pad0[0x40];
    s32 unk40;
};

s32 func_00552660(struct func_00552660_arg0 *arg0) {
    return arg0->unk40;
}
