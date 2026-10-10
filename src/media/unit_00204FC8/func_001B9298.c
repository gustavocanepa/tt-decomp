#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_001B9298_arg0 {
    char pad0[0xD0];
    s32 unkD0;
};

void func_001B9298(struct func_001B9298_arg0 *arg0, s32 arg1) {
    arg0->unkD0 = arg1;
}
