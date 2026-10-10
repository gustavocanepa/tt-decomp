#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_005514B0_arg0 {
    char pad0[0xE3E4];
    s32 unkE3E4;
};

void func_005514B0(struct func_005514B0_arg0 *arg0, s32 arg1) {
    arg0->unkE3E4 = arg1;
}
