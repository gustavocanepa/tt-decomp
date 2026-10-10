#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_005599D0_arg0 {
    char pad0[0x1171];
    s8 unk1171;
};

void func_005599D0(struct func_005599D0_arg0 *arg0, s8 arg1) {
    arg0->unk1171 = arg1;
}
