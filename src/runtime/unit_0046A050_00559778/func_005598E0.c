#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_005598E0_arg0 {
    char pad0[0x190];
    s32 unk190;
};

void func_005598E0(struct func_005598E0_arg0 *arg0, s32 arg1) {
    arg0->unk190 = arg1;
}
