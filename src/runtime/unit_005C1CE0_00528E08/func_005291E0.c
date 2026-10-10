#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_005291E0_arg0 {
    char pad0[0x194];
    s32 unk194;
};

void func_005291E0(struct func_005291E0_arg0 *arg0, s32 arg1) {
    arg0->unk194 = arg1;
}
