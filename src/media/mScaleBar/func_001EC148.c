#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_001EC148_arg0 {
    char pad0[0xF8];
    s32 unkF8;
};

void func_001EC148(struct func_001EC148_arg0 *arg0, s32 arg1) {
    arg0->unkF8 = arg1;
}
