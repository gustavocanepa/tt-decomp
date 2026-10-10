#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_003641F8_arg0 {
    char pad0[0xA7];
    s8 unkA7;
};

void func_003641F8(struct func_003641F8_arg0 *arg0, s8 arg1) {
    arg0->unkA7 = arg1;
}
