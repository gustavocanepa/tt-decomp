#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_005514F0_arg0 {
    char pad0[0xE3F8];
    s32 unkE3F8;
};

void func_005514F0(struct func_005514F0_arg0 *arg0, s32 arg1) {
    arg0->unkE3F8 = arg1;
}
