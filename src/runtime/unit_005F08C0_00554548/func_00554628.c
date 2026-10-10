#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00554628_arg0 {
    char pad0[0xE30];
    s32 unkE30;
};

void func_00554628(struct func_00554628_arg0 *arg0, s32 arg1) {
    arg0->unkE30 = arg1;
}
