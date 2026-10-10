#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00417E30_arg0 {
    char pad0[0x1E0];
    f32 unk1E0;
};

void func_00417E30(struct func_00417E30_arg0 *arg0, f32 fparg0) {
    arg0->unk1E0 = fparg0;
}
