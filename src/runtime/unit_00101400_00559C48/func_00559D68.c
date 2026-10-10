#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00559D68_arg0 {
    char pad0[0x4848];
    s32 unk4848;
};

void func_00559D68(struct func_00559D68_arg0 *arg0, s32 arg1) {
    arg0->unk4848 = arg1;
}
