#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00559D30_arg0 {
    char pad0[0x12B0];
    s32 unk12B0;
};

void func_00559D30(struct func_00559D30_arg0 *arg0, s32 arg1) {
    arg0->unk12B0 = arg1;
}
