#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00560410_arg0 {
    char pad0[0x148];
    s32 unk148;
};

void func_00560410(struct func_00560410_arg0 *arg0, s32 arg1) {
    arg0->unk148 = arg1;
}
