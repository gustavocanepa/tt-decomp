#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0052F1C0_arg0 {
    char pad0[0xDC];
    s16 unkDC;
};

void func_0052F1C0(struct func_0052F1C0_arg0 *arg0, s16 arg1) {
    arg0->unkDC = arg1;
}
