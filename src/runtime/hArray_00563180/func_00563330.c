#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00563330_arg0 {
    char pad0[0xA8];
    s32 unkA8;
};

void func_00563330(struct func_00563330_arg0 *arg0, s32 arg1) {
    arg0->unkA8 = arg1;
}
