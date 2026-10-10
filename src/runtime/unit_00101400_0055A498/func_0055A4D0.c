#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0055A4D0_arg0 {
    char pad0[0xDE8];
    s32 unkDE8;
};

void func_0055A4D0(struct func_0055A4D0_arg0 *arg0, s32 arg1) {
    arg0->unkDE8 = arg1;
}
