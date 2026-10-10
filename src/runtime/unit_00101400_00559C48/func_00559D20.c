#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00559D20_arg0 {
    char pad0[0x12AC];
    s32 unk12AC;
};

s32 func_00559D20(struct func_00559D20_arg0 *arg0) {
    return arg0->unk12AC;
}
