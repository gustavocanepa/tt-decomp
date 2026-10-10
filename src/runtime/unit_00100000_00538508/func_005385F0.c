#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_005385F0_arg0 {
    char pad0[0x34];
    f32 unk34;
};

void func_005385F0(struct func_005385F0_arg0 *arg0, f32 fparg0) {
    arg0->unk34 = fparg0;
}
