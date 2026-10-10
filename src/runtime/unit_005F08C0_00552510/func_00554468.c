#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00554468_arg0 {
    char pad0[0xE0C];
    s32 unkE0C;
};

void func_00554468(struct func_00554468_arg0 *arg0, s32 arg1) {
    arg0->unkE0C = arg1;
}
