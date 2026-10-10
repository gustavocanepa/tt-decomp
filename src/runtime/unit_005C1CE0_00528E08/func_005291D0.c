#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_005291D0_arg0 {
    char pad0[0x18C];
    s32 unk18C;
};

void func_005291D0(struct func_005291D0_arg0 *arg0, s32 arg1) {
    arg0->unk18C = arg1;
}
