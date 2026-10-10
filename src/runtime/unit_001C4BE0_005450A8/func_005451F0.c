#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_005451F0_arg0 {
    char pad0[0xE0];
    f32 unkE0;
};

void func_005451F0(struct func_005451F0_arg0 *arg0, f32 fparg0) {
    arg0->unkE0 = fparg0;
}
