#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00417E40_arg0 {
    char pad0[0x1E4];
    f32 unk1E4;
};

void func_00417E40(struct func_00417E40_arg0 *arg0, f32 fparg0) {
    arg0->unk1E4 = fparg0;
}
