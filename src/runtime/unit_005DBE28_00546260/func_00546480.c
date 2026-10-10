#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00546480_arg0 {
    char pad0[0x124];
    s32 unk124;
};

void func_00546480(struct func_00546480_arg0 *arg0, s32 arg1) {
    arg0->unk124 = arg1;
}
