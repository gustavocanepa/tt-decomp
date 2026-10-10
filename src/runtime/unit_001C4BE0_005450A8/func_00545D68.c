#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00545D68_arg0 {
    char pad0[0x108];
    f32 unk108;
};

void func_00545D68(struct func_00545D68_arg0 *arg0, f32 fparg0) {
    arg0->unk108 = fparg0;
}
