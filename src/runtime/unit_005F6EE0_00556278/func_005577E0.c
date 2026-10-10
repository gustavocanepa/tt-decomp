#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_005577E0_arg0 {
    char pad0[0x54];
    s8 unk54;
};

void func_005577E0(struct func_005577E0_arg0 *arg0, s8 arg1) {
    arg0->unk54 = arg1;
}
