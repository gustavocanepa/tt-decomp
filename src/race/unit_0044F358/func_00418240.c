#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00418240_arg0 {
    char pad0[0x2D4];
    f32 unk2D4;
};

void func_00418240(struct func_00418240_arg0 *arg0, f32 fparg0) {
    arg0->unk2D4 = fparg0;
}
