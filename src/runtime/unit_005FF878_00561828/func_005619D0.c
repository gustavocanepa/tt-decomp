#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_005619D0_arg0 {
    char pad0[0x29];
    s8 unk29;
};

void func_005619D0(struct func_005619D0_arg0 *arg0, s8 arg1) {
    arg0->unk29 = arg1;
}
