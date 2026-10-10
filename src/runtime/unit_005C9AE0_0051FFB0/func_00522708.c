#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00522708_arg0 {
    char pad0[0x140B8];
    s32 unk140B8;
};

void func_00522708(struct func_00522708_arg0 *arg0, s32 arg1) {
    arg0->unk140B8 = arg1;
}
