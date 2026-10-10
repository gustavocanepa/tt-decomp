#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00561CB0_arg0 {
    char pad0[0xB20];
    s32 unkB20;
};

void func_00561CB0(struct func_00561CB0_arg0 *arg0, s32 arg1) {
    arg0->unkB20 = arg1;
}
