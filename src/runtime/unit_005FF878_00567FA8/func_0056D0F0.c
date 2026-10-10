#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0056D0F0_arg0 {
    char pad0[0x18];
    s32 unk18;
    s32 unk1C;
};

void func_0056D0F0(struct func_0056D0F0_arg0 *arg0, s32 arg1) {
    arg0->unk18 = arg1;
    arg0->unk1C = 1;
}
