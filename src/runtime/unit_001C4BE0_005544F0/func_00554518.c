#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00554518_arg0 {
    char pad0[0xE24];
    s32 unkE24;
};

void func_00554518(struct func_00554518_arg0 *arg0, s32 arg1) {
    arg0->unkE24 = arg1;
}
