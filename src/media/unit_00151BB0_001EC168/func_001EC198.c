#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_001EC198_arg0 {
    char pad0[0xF0];
    f32 unkF0;
};

void func_001EC198(struct func_001EC198_arg0 *arg0, f32 fparg0) {
    arg0->unkF0 = fparg0;
}
