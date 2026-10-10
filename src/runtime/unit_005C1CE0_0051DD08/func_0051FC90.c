#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0051FC90_arg0 {
    char pad0[0xC0];
    s32 unkC0;
};

void func_0051FC90(struct func_0051FC90_arg0 *arg0, s32 arg1) {
    arg0->unkC0 = arg1;
}
