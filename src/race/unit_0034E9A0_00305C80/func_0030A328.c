#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0030A328_arg0 {
    char pad0[0x486];
    s8 unk486;
    s8 unk487;
};

void func_0030A328(struct func_0030A328_arg0 *arg0, s8 arg1) {
    arg0->unk486 = arg1;
    arg0->unk487 = 0;
}
