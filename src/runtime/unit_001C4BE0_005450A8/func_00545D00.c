#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00545D00_arg0 {
    char pad0[0xFC];
    s32 unkFC;
};

void func_00545D00(struct func_00545D00_arg0 *arg0, s32 arg1) {
    arg0->unkFC = arg1;
}
