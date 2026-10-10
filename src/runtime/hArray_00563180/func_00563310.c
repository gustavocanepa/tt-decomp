#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00563310_arg0 {
    char pad0[0xA0];
    s32 unkA0;
};

void func_00563310(struct func_00563310_arg0 *arg0, s32 arg1) {
    arg0->unkA0 = arg1;
}
