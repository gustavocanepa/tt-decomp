#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00417D30_arg0 {
    char pad0[0x144];
    f32 unk144;
};

void func_00417D30(struct func_00417D30_arg0 *arg0, f32 fparg0) {
    arg0->unk144 = fparg0;
}
