#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00556908_arg0 {
    char pad0[0xC];
    s32 unkC;
};

void func_00556908(struct func_00556908_arg0 *arg0, s32 arg1) {
    arg0->unkC = arg1;
}
