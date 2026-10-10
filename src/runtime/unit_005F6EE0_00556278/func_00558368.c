#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00558368_arg0 {
    char pad0[0x34];
    f32 unk34;
};

void func_00558368(struct func_00558368_arg0 *arg0, f32 fparg0) {
    arg0->unk34 = fparg0;
}
