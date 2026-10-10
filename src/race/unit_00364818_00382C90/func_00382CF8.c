#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00382CF8_arg0 {
    char pad0[0x4C];
    f32 unk4C;
};

void func_00382CF8(struct func_00382CF8_arg0 *arg0, f32 fparg0) {
    arg0->unk4C = fparg0;
}
