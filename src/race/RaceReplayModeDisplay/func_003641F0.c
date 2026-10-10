#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_003641F0_arg0 {
    char pad0[0xA5];
    s8 unkA5;
};

void func_003641F0(struct func_003641F0_arg0 *arg0, s8 arg1) {
    arg0->unkA5 = arg1;
}
