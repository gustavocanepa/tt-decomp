#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0038FBC0_arg0 {
    char pad0[0xA30];
    s32 unkA30;
};

void func_0038FBC0(struct func_0038FBC0_arg0 *arg0, s32 arg1) {
    arg0->unkA30 = arg1;
}
