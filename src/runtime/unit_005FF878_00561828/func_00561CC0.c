#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00561CC0_arg0 {
    char pad0[0xB24];
    s32 unkB24;
};

void func_00561CC0(struct func_00561CC0_arg0 *arg0, s32 arg1) {
    arg0->unkB24 = arg1;
}
