#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00559D40_arg0 {
    char pad0[0x12B4];
    s32 unk12B4;
};

void func_00559D40(struct func_00559D40_arg0 *arg0, s32 arg1) {
    arg0->unk12B4 = arg1;
}
