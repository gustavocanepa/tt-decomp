#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00418230_arg0 {
    char pad0[0x2D0];
    f32 unk2D0;
};

void func_00418230(struct func_00418230_arg0 *arg0, f32 fparg0) {
    arg0->unk2D0 = fparg0;
}
