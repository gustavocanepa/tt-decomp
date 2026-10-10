#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_005633E0_arg0 {
    char pad0[0x7];
    s8 unk7;
};

void func_005633E0(struct func_005633E0_arg0 *arg0, s8 arg1) {
    arg0->unk7 = arg1;
}
