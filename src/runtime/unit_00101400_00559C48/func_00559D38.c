#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00559D38_arg0 {
    char pad0[0x12B0];
    s32 unk12B0;
};

s32 func_00559D38(struct func_00559D38_arg0 *arg0) {
    return arg0->unk12B0;
}
