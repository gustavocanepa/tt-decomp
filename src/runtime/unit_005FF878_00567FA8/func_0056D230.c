#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_0056D230_arg0 {
    char pad0[0x4];
    s32 unk4;
    s32 unk8;
};

void func_0056D230(struct func_0056D230_arg0 *arg0, s32 arg1) {
    arg0->unk8 = arg1;
    arg0->unk4 = 3;
}
