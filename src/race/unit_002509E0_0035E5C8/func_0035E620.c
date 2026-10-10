#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0035E620_arg0 {
    char pad0[0xA40];
    s8 unkA40;
};

void func_0035E620(struct func_0035E620_arg0 *arg0, s8 arg1) {
    arg0->unkA40 = arg1;
}
