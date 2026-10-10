#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_005450A0_arg0 {
    char pad0[0xD4];
    s32 unkD4;
};

void func_005450A0(struct func_005450A0_arg0 *arg0, s32 arg1) {
    arg0->unkD4 = arg1;
}
