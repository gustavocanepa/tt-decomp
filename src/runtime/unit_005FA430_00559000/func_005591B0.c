#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_005591B0_arg0 {
    char pad0[0x1D];
    s8 unk1D;
};

void func_005591B0(struct func_005591B0_arg0 *arg0, s8 arg1) {
    arg0->unk1D = arg1;
}
