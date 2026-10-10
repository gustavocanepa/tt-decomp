#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0052C738_arg0 {
    char pad0[0xE8];
    f32 unkE8;
};

void func_0052C738(struct func_0052C738_arg0 *arg0, f32 fparg0) {
    arg0->unkE8 = fparg0;
}
