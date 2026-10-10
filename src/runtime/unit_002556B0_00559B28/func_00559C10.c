#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00559C10_arg0 {
    char pad0[0x5454];
    s32 unk5454;
};

void func_00559C10(struct func_00559C10_arg0 *arg0, s32 arg1) {
    arg0->unk5454 = arg1;
}
