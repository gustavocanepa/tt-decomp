#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00370488_arg0 {
    char pad0[0x120];
    s32 unk120;
};

void func_00370488(struct func_00370488_arg0 *arg0, s32 arg1) {
    arg0->unk120 = arg1;
}
