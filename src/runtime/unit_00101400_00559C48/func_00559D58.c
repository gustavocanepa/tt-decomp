#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00559D58_arg0 {
    char pad0[0x4840];
    s32 unk4840;
};

s32 func_00559D58(struct func_00559D58_arg0 *arg0) {
    return arg0->unk4840;
}
