#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0052F1D0_arg0 {
    char pad0[0xDE];
    s16 unkDE;
};

void func_0052F1D0(struct func_0052F1D0_arg0 *arg0, s16 arg1) {
    arg0->unkDE = arg1;
}
