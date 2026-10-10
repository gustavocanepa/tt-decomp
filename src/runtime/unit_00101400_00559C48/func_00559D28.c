#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00559D28_arg0 {
    char pad0[0x12AC];
    s32 unk12AC;
};

void func_00559D28(struct func_00559D28_arg0 *arg0, s32 arg1) {
    arg0->unk12AC = arg1;
}
