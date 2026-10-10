#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00187CA8_arg0 {
    char pad0[0xC0];
    s32 unkC0;
};

void func_00187CA8(struct func_00187CA8_arg0 *arg0) {
    if (arg0->unkC0 == 2) {
        arg0->unkC0 = 1;
    }
}
