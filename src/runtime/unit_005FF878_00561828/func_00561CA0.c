#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00561CA0_arg0 {
    char pad0[0xB1C];
    s32 unkB1C;
};

void func_00561CA0(struct func_00561CA0_arg0 *arg0, s32 arg1) {
    arg0->unkB1C = arg1;
}
