#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00558878_arg0 {
    char pad0[0x23];
    s8 unk23;
};

void func_00558878(struct func_00558878_arg0 *arg0, s8 arg1) {
    arg0->unk23 = arg1;
}
