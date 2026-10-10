#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00563320_arg0 {
    char pad0[0xA4];
    s32 unkA4;
};

void func_00563320(struct func_00563320_arg0 *arg0, s32 arg1) {
    arg0->unkA4 = arg1;
}
