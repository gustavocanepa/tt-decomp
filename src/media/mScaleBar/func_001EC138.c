#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_001EC138_arg0 {
    char pad0[0xF4];
    s32 unkF4;
};

void func_001EC138(struct func_001EC138_arg0 *arg0, s32 arg1) {
    arg0->unkF4 = arg1;
}
