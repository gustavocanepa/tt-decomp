#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00240958_arg0 {
    char pad0[0x1A8];
    f32 unk1A8;
};

void func_00240958(struct func_00240958_arg0 *arg0, f32 fparg0) {
    arg0->unk1A8 = (f32) (fparg0 / 0x1.e000000000000p+5f);
}
