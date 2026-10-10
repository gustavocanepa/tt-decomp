#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00557EF0_arg0 {
    char pad0[0x68];
    f32 unk68;
};

void func_00557EF0(struct func_00557EF0_arg0 *arg0, f32 fparg0) {
    arg0->unk68 = fparg0;
}
