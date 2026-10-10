#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0033C820_arg0 {
    char pad0[0xDD8];
    s32 unkDD8;
};

void func_0033C820(struct func_0033C820_arg0 *arg0, s32 arg1) {
    arg0->unkDD8 = arg1;
}
